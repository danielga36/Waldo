//code name project pointer 
//transmitter code>>>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <I2Cdev.h>    
#include <MPU6050.h>

int ledPin=3;
const int LBUT = 7;  //define left button digital pin 7
const int RBUT = 6;  //define right button digital pin 6
int buttonStatel = 0;   //buttonleft
int buttonStater = 0;   //buttonright

RF24 radio(10, 9); // CE, CSN

const byte address[6] = "00001";

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int count = 0;

struct big_data{  //structure for sending all the data
int16_t gxaxis; 
int16_t gzaxis;

int lbutton;   
int rbutton;   
};
big_data data;


void setup() {
  pinMode(ledPin, OUTPUT); // set LED pin as output

  pinMode(LBUT, INPUT_PULLUP);
  digitalWrite(LBUT, HIGH);

  pinMode(RBUT, INPUT_PULLUP);
  digitalWrite(RBUT, HIGH);


  mpu.initialize();
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
  }

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}



void loop()
{

  analogWrite(ledPin, 125); // set LED brightness using PWM BRIGHTNESS OF 50% of 255

  int angleV = 0;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  data.gxaxis=gx;
  data.gzaxis=gz;


  //button>>>>>>>>>>>>>>>>>>>>>>>>>>>>> START

  if (digitalRead(LBUT) == LOW) {      
  buttonStatel = 1;
    analogWrite(ledPin, 0); // set LED brightness using PWM brightness of led set to 50%of255
    delay(10); 
  }
  else
  {
    buttonStatel = 0;
  }
  



  if (digitalRead(RBUT) == LOW){
    buttonStater = 1;
    analogWrite(ledPin, 0); // set LED brightness using PWM brightness of led set to 50%of255
    delay(10); 
  }
  else
  {
    buttonStater = 0;
  }

  data.lbutton=buttonStatel;
  data.rbutton=buttonStater;

  radio.write(&data,sizeof(big_data));  //sends the struct data packet
  delay(10);
} 

  
  
