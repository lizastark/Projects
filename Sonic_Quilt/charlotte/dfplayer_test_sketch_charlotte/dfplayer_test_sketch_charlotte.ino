/*

  DFPLAYER MINI BASIC PLAY
  Charlotte Test Sketch
  May 16, 2018
  Liza Stark

  This does not use the DFPlayer Mini Library on DFRobot's site and instead uses
  commands developed and documented by Ype Brada:
  https://forum.banggood.com/forum-topic-59997.html

  Schematic and module data sheet/info are here:
  https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299

  Very important: Use serial 1K resistors on RX and TX
  to suppress noise
  Connect Sound module board RX to Arduino pin 4 <-- This is pin 10 on the example on the DFRobot site
  Connect Sound module board TX to Arduino pin 7 <-- This is pin 11 on the example on the DFRobot site

  DEBUGGING NOTE: If the player suddenly stops working, uncomment or comment out the serial.printlns
  inside of the for loops with the commands. I have no idea why some work with it, some don't,
  and some flip back and forth, but this was the solution.

*/

#include "SoftwareSerial.h"
SoftwareSerial mySerial(4, 7);
char play[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x01, 0xFE, 0xF7, 0XEF};
char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x1E, 0xFE, 0xD7, 0XEF};
//char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x05, 0xFE, 0xF0, 0XEF}; //volume at 5


void setup () {
  mySerial.begin (9600);
  delay(1000);

  Serial.begin(9600);

  Serial.println("Sending info");

  // Set volume to 30
  for (int count = 0; count < 10; count++) {
    mySerial.write(setVolume[count]);
    // Serial.println("volume");
  }


  // Play file once
  for (int count = 0; count < 10; count++) {
    mySerial.write( play[count]);
    // Serial.println("command");
  }



}

void loop () {

}


