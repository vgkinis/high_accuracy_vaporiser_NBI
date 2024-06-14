#include <Arduino.h> //Include to run in Visual Code Studio
#include <Wire.h>  // Include the Wire library for I2C communication
#include <Math.h>  // Include the Math library


#define I2C_LOWDRIVER_ADRESS (0x59) // Default address for Lowdriver 1011001

// Define the pump variables
boolean bPumpState = false;           //variables to store pump parameters
uint8_t nPumpVoltageByte = 0x00;
uint8_t nFrequencyByte = 0x0C;

// Set pump parameters
uint16_t setv = 150;  // Initial voltage (in volts)
uint16_t setf = 100;  // Initial frequency (in Hz)
unsigned long expt = 50000;  // Experiment time in milliseconds

void selectControlRegisters() {  //subfunctions to change between register pages of the mp-Lowdriver
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0xFF);
  Wire.write(0x00);
  Wire.endTransmission();
}

void selectMemoryRegisters() {
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0xFF);
  Wire.write(0x01);
  Wire.endTransmission();
}

void Lowdriver_init() {               //initialize mp-Lowdriver 
  Serial.println("Initializing Lowdriver...");
  selectControlRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x01);//Select (Control) Register 0x01
  Wire.write(0x02);//Set Gain 0-3 (0x00-0x03 25v-100v)
  Wire.write(0x00);//Take device out of standby mode
  Wire.write(0x01);//Set sequencer to play WaveForm ID #1
  Wire.write(0x00);//End of sequence
  Wire.endTransmission();
  Serial.println("Control registers configured.");
  selectMemoryRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x00); //Select Register 0x00
  Wire.write(0x05); //Header size –1
  Wire.write(0x80); //Start address upper byte (page), also indicates Mode 3
  Wire.write(0x06); //Start address lower byte (in page address)
  Wire.write(0x00); //Stop address upper byte
  Wire.write(0x09); //Stop address Lower byte
  Wire.write(0x00); //Repeat count, play WaveForm once                      // 0 = infinite loop
  Wire.write(0x00); //Initial Amplitude 0V
  Wire.write(0x0C); //Initial Frequency (100Hz)
  Wire.write(100);  //cycles
  Wire.write(0x00); //envelope
  Wire.endTransmission();;
  delay(10);
  Serial.println("Memory registers configured.");
  selectControlRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x02); //Set page register to control space
  Wire.write(0x01); //Set GO bit (execute WaveForm sequence)ss
  Wire.endTransmission();
  bPumpState = false;
  nPumpVoltageByte = 255;
  Serial.println("Lowdriver initialization complete.");
}

void Lowdriver_setvoltage(uint8_t _voltage) {     //set mp-Lowdriver frequency (possible inputs: 0-150Vpp)
  float temp = _voltage; temp*=255; temp/=150;   //150Vpp = 0xFF for Gain = 0x02 (default)
  nPumpVoltageByte = constrain(temp,0,255);
  Serial.println(nPumpVoltageByte);
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x02); //Stop Waveform playback
  Wire.write(0x00);
  Wire.endTransmission();
  selectMemoryRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x06); //Set page register to control space
  Wire.write((bPumpState ? nPumpVoltageByte : 0));    //0-255
  Wire.endTransmission();
  delay(10);
  selectControlRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x02); //Start Waveform playback
  Wire.write(0x01);
  Wire.endTransmission();
  Serial.println("Voltage set.");
}

void Lowdriver_setfrequency(uint16_t _frequency) {  //set mp-Lowdriver frequency (possible inputs: 8-800Hz)
  float temp = _frequency; temp/=7.8125;
  nFrequencyByte = constrain(temp,1,255);
  if (nFrequencyByte==0) nFrequencyByte=1;          //frequency 0Hz is not allowed
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x02); //Stop Waveform playback
  Wire.write(0x00);
  Wire.endTransmission();
  selectMemoryRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x07); //Set page register to control space
  Wire.write(nFrequencyByte);    //0-255
  Wire.endTransmission(); 
  delay(10);
  selectControlRegisters();
  Wire.beginTransmission(I2C_LOWDRIVER_ADRESS);
  Wire.write(0x02); //Start Waveform playback
  Wire.write(0x01);
  Wire.endTransmission();
  Serial.println("Frequency set.");
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Starting setup...");
  Lowdriver_init(); //needs double init
  Lowdriver_init();
  Serial.println("Setup complete.");
}

void loop() {
  bPumpState = true;
  Lowdriver_setvoltage(setv);    //Turn pump on by setting a target Voltage > 0V
  Lowdriver_setfrequency(setf);  //set frequency to target
  delay(expt);
  bPumpState = false;
  Lowdriver_setvoltage(0);
  Lowdriver_setfrequency(0);      //Turn pump off by setting a Voltage = 0V
  delay(expt);
}
