#include <Wire.h>
#include <LiquidCrystal.h>

const int ADDRESS = 0x40; // Standard address for Liquid Flow Sensors

const bool VERBOSE_OUTPUT = true; // set to false for less verbose output

// EEPROM Addresses for factor and unit of calibration fields 0,1,2,3,4.
const uint16_t SCALE_FACTOR_ADDRESSES[] = {0x2B6, 0x5B6, 0x8B6, 0xBB6, 0xEB6};
const uint16_t UNIT_ADDRESSES[] =         {0x2B7, 0x5B7, 0x8B7, 0xBB7, 0xEB6};

// Flow Units and their respective codes.
const char    *FLOW_UNIT[] = {"nl/min", "ul/min", "ml/min", "ul/sec", "ml/h"};
const uint16_t FLOW_UNIT_CODES[] = {2115, 2116, 2117, 2100, 2133};

uint16_t scale_factor;
const char *unit;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// -----------------------------------------------------------------------------
// Arduino setup routine, just runs once:
// -----------------------------------------------------------------------------
void setup() {
  int ret;

  uint16_t user_reg;
  uint16_t scale_factor_address;

  uint16_t unit_code;

  byte crc1;
  byte crc2;

  Serial.begin(9600); // initialize serial communication
  Wire.begin();       // join i2c bus (address optional for master)

  do {
    delay(1000); // Error handling for example: wait a second, then try again

    // Soft reset the sensor
    Wire.beginTransmission(ADDRESS);
    Wire.write(0xFE);
    ret = Wire.endTransmission();
    if (ret != 0) {
      Serial.println("Error while sending soft reset command, retrying...");
      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
     // Print a message to the LCD.
      lcd.print("Error code");
      continue;
    }
    delay(50); // wait long enough for reset

    // Read the user register to get the active configuration field
    Wire.beginTransmission(ADDRESS);
    Wire.write(0xE3);
    ret = Wire.endTransmission();
    if (ret != 0) {
      Serial.println("Error while setting register read mode");
      continue;
    }

    Wire.requestFrom(ADDRESS, 2);
    if (Wire.available() < 2) {
      Serial.println("Error while reading register settings");
      continue;
    }
    user_reg  = Wire.read() << 8;
    user_reg |= Wire.read();

    // The active configuration field is determined by bit <6:4>
    // of the User Register
    scale_factor_address = SCALE_FACTOR_ADDRESSES[(user_reg & 0x0070) >> 4];

    // Read scale factor and measurement unit
    Wire.beginTransmission(ADDRESS);
    Wire.write(0xFA); // Set EEPROM read mode
    // Write left aligned 12 bit EEPROM address
    Wire.write(scale_factor_address >> 4);
    Wire.write((scale_factor_address << 12) >> 8);
    ret = Wire.endTransmission();
    if (ret != 0) {
      Serial.println("Error during write EEPROM address");
      continue;
    }

    // Read the scale factor and the adjacent unit
    Wire.requestFrom(ADDRESS, 6);
    if (Wire.available() < 6) {
      Serial.println("Error while reading EEPROM");
      continue;
    }
    scale_factor = Wire.read() << 8;
    scale_factor|= Wire.read();
    crc1         = Wire.read();
    unit_code    = Wire.read() << 8;
    unit_code   |= Wire.read();
    crc2         = Wire.read();

    switch (unit_code) {
     case 2115:
       { unit = FLOW_UNIT[0]; }
       break;
     case 2116:
       { unit = FLOW_UNIT[1]; }
       break;
     case 2117:
       { unit = FLOW_UNIT[2]; }
       break;
     case 2100:
       { unit = FLOW_UNIT[3]; }
       break;
     case 2133:
       { unit = FLOW_UNIT[4]; }
       break;
     default:
       Serial.println("Error: No matching unit code");
       break;
   }

    if (VERBOSE_OUTPUT) {
      Serial.println();
      Serial.println("-----------------------");
      Serial.print("Scale factor: ");
      Serial.println(scale_factor);
      Serial.print("Unit: ");
      Serial.print(unit);
      Serial.print(", code: ");
      Serial.println(unit_code);
      Serial.println("-----------------------");
      Serial.println();
    }

    // Switch to measurement mode
    Wire.beginTransmission(ADDRESS);
    Wire.write(0xF1);
    ret = Wire.endTransmission();
    if (ret != 0) {
      Serial.println("Error during write measurement mode command");
    }
  } while (ret != 0);
}

// -----------------------------------------------------------------------------
// The Arduino loop routine runs over and over again forever:
// -----------------------------------------------------------------------------
void loop() {
  int ret;
  uint16_t raw_sensor_value;
  float sensor_reading;

  Wire.requestFrom(ADDRESS, 2); // reading 2 bytes ignores the CRC byte
  if (Wire.available() < 2) {
    Serial.println("Error while reading flow measurement");

  } else {
    raw_sensor_value  = Wire.read() << 8; // read the MSB from the sensor
    raw_sensor_value |= Wire.read();      // read the LSB from the sensor
    sensor_reading = ((int16_t) raw_sensor_value) / ((float) scale_factor);

    Serial.print("Sensor reading: ");
    Serial.print(sensor_reading);
    Serial.print(" ");
    Serial.println(unit);
  }

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Sensor value :");

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(sensor_reading);

  lcd.setCursor(6, 1);
  // print the number of seconds since reset:
  lcd.print(unit);

  delay(3000); // milliseconds delay between reads (for demo purposes)

}