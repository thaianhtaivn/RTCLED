/* SevSeg Counter Example
 
 Copyright 2017 Dean Reading
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */
 

#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
  byte numDigits = 4;
  byte digitPins[] = {13, 13, 12, 10};
  byte segmentPins[] = {7, 3, 5, 4, 6, 8, 9};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = P_TRANSISTORS; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros

void setup() {
//    
//  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
//  updateWithDelays, leadingZeros);
//  sevseg.setBrightness(90);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  //pinMode(A0, OUTPUT);
}

void loop() {

  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
}

/// END ///
