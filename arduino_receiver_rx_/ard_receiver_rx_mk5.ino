//code name project pointer 
//receiver code>>>


#include <Wire.h>
#include <I2Cdev.h>    
#include <MPU6050.h>
#include <Mouse.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>  


RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";



int buttonStatel ;   //buttonleft
int buttonStater ;   //buttonright

int16_t ax, ay, az, gx, gy, gz;
int vx, vy, vx_prec, vy_prec;

struct big_data{  //structure for receiving all the data
int16_t gxaxis;
int16_t gzaxis;
int lbutton;   //button
int rbutton;   //button
};

big_data data;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Mouse.begin();
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}


void loop() 
{
  data.lbutton = 0;
 if ( radio.available()) {
    while (radio.available())
    {
      radio.read(&data, sizeof(big_data));  //starts reading the struct data packet 

      vy = -(data.gxaxis + 150) / 200;  //takes the raw values , adjust the sensitivity here !!!
      vx = -(data.gzaxis - 100) / 200;

      
      Mouse.move(vx, vy); //moves the pointer

      buttonStatel=data.lbutton;
      buttonStater=data.rbutton;

      if (data.lbutton == 1) {
        if (!Mouse.isPressed(MOUSE_LEFT)) {
        Mouse.press(MOUSE_LEFT);
        }
      }
      
      else {
        if (Mouse.isPressed(MOUSE_LEFT)) {
        Mouse.release(MOUSE_LEFT);
        }
      }


      if (data.rbutton == 1) {
        if (!Mouse.isPressed(MOUSE_RIGHT)) {
        Mouse.press(MOUSE_RIGHT);
        }
      }

      else {
        if (Mouse.isPressed(MOUSE_RIGHT)) {
        Mouse.release(MOUSE_RIGHT);
        }
      }


    }
  }    
}  