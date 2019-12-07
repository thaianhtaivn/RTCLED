
#include <SevSeg.h>
#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
SevSeg sevseg; //Instantiate a seven segment controller object
unsigned int  Sec, Min, Hour ;
char checksum_IN;
unsigned long time1, Time_Reset;

unsigned long lastChangedTime;


RTC_DS3231 rtc;

byte numDigits = 4;
byte digitPins[] = {13, 10, 11, 12};
byte segmentPins[] = {9, 8, 7, 6, 5, 4, 3, 2};
bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
byte hardwareConfig = N_TRANSISTORS; // See README.md for options
bool updateWithDelays = false; // Default. Recommended
bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros

void setup()
{

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.refreshDisplay();
  
    if (! rtc.begin()) {
    //Serial.println("Couldn't find RTC");
    while (1);
  }
  //if (rtc.lostPower()) {
    //Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2019, 12, 6, 11, 8, 0));
  //}

}
//-----------------------------------
void Hold(unsigned int delayTime) {
  unsigned long endTime = (unsigned long) (millis() + delayTime);
  while (millis() < endTime) {
    sevseg.refreshDisplay();
  }
}
//-----------------------------------
void loop()
{
  DateTime now = rtc.now();
  Sec = now.second();
  Min = now.minute();
  Hour = now.hour();
  if(Sec%2 ==0)
    sevseg.setNumber((Hour * 100 + Min),2);
  else
    sevseg.setNumber((Hour * 100 + Min));
  sevseg.refreshDisplay();
//  if((Sec%2 == 0)
//    digitalWrite (2, HIGH);
//  else
//    digitalWrite (2, LOW);
//    
}
