#include <Wire.h>
#include <math.h>


//Select frequency... between 50 and 800 Hz
int freq=120; //Hz
//How many minutes for the meaurement?
float min=2; //min

//PUMP 1: select voltage... between 16 and 250V
int p1=250; //V
//PUMP 2: select voltage
int p2=250; //V
//PUMP 3: select voltage
int p3=250; //V 
//PUMP 4: select voltage
int p4=10; //V-----------------------------------------------------------------------------------------

int num=0;

//convert the frequency into a number
num= ConvertFrequency(freq);

//convert minutes into seconds
float sec=60*min*1000;

//convert the voltage into a number
int numP1=0.125*p1; //PUMP 1
int numP2=0.125*p2; //PUMP 2
int numP3=0.125*p3; //PUMP 3
int numP4=0.125*p4; //PUMP 4

#define Addr 0x7B
#define TASTER 3
#define LED 13
#define I2C_DEVICEID 0x00
#define I2C_POWERMODE 0x01
#define I2C_FREQUENCY 0x02
#define I2C_SHAPE 0x03
#define I2C_BOOST 0x04
#define I2C_PVOLTAGE 0x06
#define I2C_P1VOLTAGE 0x06
#define I2C_P2VOLTAGE 0x07
#define I2C_P3VOLTAGE 0x08
#define I2C_P4VOLTAGE 0x09
#define I2C_UPDATEVOLTAGE 0x06
#define I2C_AUDIO 0x05


//the setup routine runs once when you press reset :
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println();
  pinMode(LED, OUTPUT);
  pinMode(TASTER, INPUT_PULLUP);
  Wire.beginTransmission(Addr);
  Wire.write(I2C_POWERMODE);  //start adress=0x01
  Wire.write(0x00);             //Adress0x01=0x01 (enable)
  Wire.write(num);       //Adress0x00=0x00 (50Hz)
  Wire.write(0x00);           //Adress0x03=0x00 (sine wave)
  Wire.write(0x00);           //Adress0x04=0x00 (800 KHz)
  Wire.write(0x00);           //Adress0x05=0x00 (audio off)
  Wire.write(numP1); //Adress0x06=0x00 (VO1) set voltage DecBin (numP1)
  Wire.write(numP2);           //Adress0x07=0x00 (VO2) set voltage
  Wire.write(numP3);           //Adress0x08=0x00 (VO3) set voltage
  Wire.write(numP4);      //Adress0x09=0x00 (VO4) set voltage
  Wire.write(0x01);           //Adress 0x00 (update)
  Wire.endTransmission();
}

//the main loop runs repeatedly:
void loop() {

  if (digitalRead(TASTER) == LOW) {

    Serial.print("Frequency = ");
    Serial.print(num,HEX);
    Serial.println(" Hz.");

    Serial.print("Voltage P1= ");
    Serial.print(p1);
    Serial.println(" V.");
    Serial.print("Voltage P2= ");
    Serial.print(p2);
    Serial.println(" V.");
    Serial.print("Voltage P3= ");
    Serial.print(p3);
    Serial.println(" V.");
    Serial.print("Voltage P4= ");
    Serial.print(p4);
    Serial.println(" V.");

    Wire.beginTransmission(Addr);
    Wire.write(I2C_POWERMODE);  //start adress
    Wire.write(0x01);           //enable pumps
    //Wire.write(0x00);           //set frequency
    Wire.endTransmission();
    digitalWrite(LED, HIGH);

    Serial.println("**START**");
    delay(sec);
    Serial.println("*****DO THE MEASUREMENT*****");
    delay(15000);
    Serial.println("**END**");
    Serial.println("");
  }

  if (digitalRead(TASTER) == HIGH) {
    Wire.beginTransmission(Addr);
    Wire.write(I2C_POWERMODE); //start adress
    Wire.write(0x00); //disable pumps
    Wire.endTransmission();
    digitalWrite(LED,LOW);
  }

  delay(100);
}



//function to convert the frequency into a number
int ConvertFrequency(int f){
  int n;
  if (f<100){
    n=1.26*f-63;
  } else if(f>=100 && f<200){
    n=0.63*f+1;
  }else if(f>=200 && f<400){
    n=0.315*f+65;
  }else{
    n=0.1575*f+129;
  }
  return(n);
}