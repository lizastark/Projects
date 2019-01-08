/*

  DFPLAYER MINI BASIC PLAY ON ATTINY 44 + SENSOR
  Sonic Quilt Prototyping
  December 11, 2018
  Liza Stark

  //Go back and include other attribution info

  If using with the ATtiny44/84, you may need to reset it by momentarily
  connecting the reset to ground.

*/

#include "SoftwareSerial.h"
//SoftwareSerial mySerial(RX, TX);
SoftwareSerial mySerial(10, 9); // ATtiny > DFplayer
//SoftwareSerial mySerial2(4, 5); // ATtiny > Arduino for sensor

// Commands for DRPlayer mini
byte play[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x01, 0xFE, 0xF7, 0XEF};
byte setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x1E, 0xFE, 0xD7, 0XEF};

// Variables for sensor
int led = 3;
int sensorPin = A1;
int sensorPin2 = A2;
int sensorVal = 0;
int sensorVal2 = 0;

void setup () {
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin2, INPUT);

  mySerial.begin (9600);
  //mySerial2.begin (9600);
  delay(1000);

  // Set volume to 30
  for (int count = 0; count < 10; count++) {
    mySerial.write(setVolume[count]);
    //Serial.println("volume");
  }

  /*
    // Doesn't work in loop alone...not sure if has something to do with loop mechanic?
    for (int count = 0; count < 10; count++) {
      mySerial.write(play[count]);
      //Serial.println("command");
    }
  */


}

void loop () {

  sensorVal = analogRead(sensorPin);
  sensorVal2 = analogRead(sensorPin2);

  mySerial.print("Input Val 1: ");
  mySerial.print(sensorVal);
  //mySerial.print("      "); // no idea why this clogs serial port
  mySerial.print("Input Val 2: ");
  mySerial.println(sensorVal2);
  //mySerial.println();

  if (sensorVal > 900 && sensorVal2 > 400) {
    playTrack();
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }



}

void playTrack() {
  // Doesn't work in loop alone...not sure if has something to do with loop mechanic?
  for (int count = 0; count < 10; count++) {
    mySerial.write(play[count]);
    //Serial.println("command");
  }
}



