#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PINLEFT            6
#define NUMPIXELS          13

static const int servoPin = 5;
int touchPin = 4;
Servo servo1;
int pos = 0;
int state = 0;
int flag;

Adafruit_NeoPixel left = Adafruit_NeoPixel(NUMPIXELS, PINLEFT, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin);
  pinMode (touchPin, INPUT);
  servo1.write(10);

  left.begin(); // This initializes the NeoPixel library.
  for (int i = 0; i < NUMPIXELS; i++) {
        left.setPixelColor(i, left.Color(0, 0, 0));
        left.show();
      }
}

void loop() {
  flag = 0;
  if (digitalRead(touchPin) == HIGH) {
    if (state == 0) {
      //delay(1000);
      Serial.println("Opening the Faceplate");
      for (int i = 0; i < NUMPIXELS; i++) {
        left.setPixelColor(i, left.Color(0, 0, 0));
        left.show();
      }
//      for (int posDegrees = 0; posDegrees <= 170; posDegrees += 6) {
//        servo1.write(posDegrees);
//        delay(20);
//      }
      servo1.write(180);
      delay(800);
      state = 1;
      flag = 1;      
    }

    if (state == 1 && flag == 0) {
      Serial.println("Closing the Faceplate");
//      for (int posDegrees = 170; posDegrees >= 0; posDegrees -= 6) {
//        servo1.write(posDegrees);
//        delay(20);
//      }
      servo1.write(0);
      state = 0;
      delay(800);
      for (int i = 0; i < NUMPIXELS; i++) {
        if(i>=5 && i <=7){
          continue;
          }
        left.setPixelColor(i, left.Color(255, 255, 255));
        left.show();
      }
      delay(2000);
      for(int i=0; i <2;i++){
        left.setPixelColor(i,left.Color(0,0,0));
        left.setPixelColor(4-i,left.Color(0,0,0));
        left.setPixelColor(12-i,left.Color(0,0,0));
        left.setPixelColor(12-4+i,left.Color(0,0,0));
        left.show();
        delay(144);
      }
        left.setPixelColor(2,left.Color(255,0,0));
        left.setPixelColor(10,left.Color(255,0,0));
        left.show(); 
        delay(625);
    
//      for(int i=1;i>=0;i--){
//        left.setPixelColor(i,left.Color(255,0,0));
//        left.setPixelColor(4-i,left.Color(255,0,0));
//        left.setPixelColor(12-i,left.Color(255,0,0));
//        left.setPixelColor(12-4+i,left.Color(255,0,0));
//        left.show();
//        delay(144);
//        } 
    }
      
    }

  }

  
