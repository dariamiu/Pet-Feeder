#include "RTClib.h"
#include <Servo.h>
#include <Wire.h>
RTC_PCF8563 rtc;
Servo servo;
int servoPin = 9; 
void setup() {
   Serial.begin(9600);
   //Wire.begin();
   rtc.begin();
   servo.attach(servoPin); 
   
}

void loop() {
  DateTime now = rtc.now();
  Serial.print("Time: ");
  Serial.print(now.hour(),DEC);
  Serial.print(':');
  Serial.print(now.minute(),DEC);
  Serial.print(':');
  Serial.print(now.second(),DEC);
  Serial.println();
  if(now.hour() == 21 && now.minute() == 50  && now.second() == 0){
    feedCat();
  }
   else{
      servo.write(90);
    }
   delay(1000);
}

void feedCat(){
    servo.write(0);
    delay(1750);
    servo.write(90);
}
