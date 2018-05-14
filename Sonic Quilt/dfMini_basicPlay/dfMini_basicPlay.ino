 /*
   
   DFPLAYER MINI BASIC PLAY
   Sonic Quilt Project 
   May 16, 2018
   Liza Stark
   
   This does not use the DFPlayer Mini Library on DFRobot's site and instead uses
   commands developed and documented by Ype Brada:
   https://forum.banggood.com/forum-topic-59997.html

   Schematic and module data sheet/info are here:
   https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299

   Very important: Use serial 1K resistors on RX and TX
   to suppress noise
   Connect Sound module board RX to Arduino pin 8 <-- This is pin 10 on the example on the DFRobot site
   Connect Sound module board TX to Arduino pin 9 <-- This is pin 11 on the example on the DFRobot site

*/

#include "SoftwareSerial.h"
SoftwareSerial mySerial(8, 9);
char play[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x01, 0xFE, 0xF7, 0XEF};

void setup () {
  mySerial.begin (9600);
  delay(1000);
  for (int count = 0; count < 10; count++) {
    mySerial.write( play[count]);
  }
}

void loop () {
}


