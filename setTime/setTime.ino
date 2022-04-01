#include <RTClib.h>
#include <Wire.h>

RTC_PCF8563 rtc;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

}

void loop()
{
 
  DateTime now = rtc.now();
  Serial.print("Time: ");
  Serial.print(now.hour(),DEC);
  Serial.print(':');
  Serial.print(now.minute(),DEC);
  Serial.print(':');
  Serial.print(now.second(),DEC);
  Serial.println();
  Serial.print("Date: ");
  Serial.print(now.month(),DEC);
  Serial.print('.');
  Serial.print(now.year(),DEC);
  Serial.println();
   delay(1000);
}
