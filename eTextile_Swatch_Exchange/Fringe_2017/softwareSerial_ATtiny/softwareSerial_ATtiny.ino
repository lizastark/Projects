/*
 * 
 * Software Serial with the ATtiny
 * 
 * This sketch reads analog values coming in from the ATtiny.
 * Be sure to read the full pinout when working with analog input:
 * http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png
 * 
 * Fall 2016
 * Computational Craft //MFADT Parsons
 * 
 * CREDITS:
quitmeyer
https://github.com/quitmeyer/ATtinyBareDemos/blob/master/ATTinyAnalogInputTOSerial/ATTinyAnalogInputTOSerial.ino

Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)
and outputs these with Software serial to the arduino uno, or Duemillanove
Hookup 
ATTINY85/45 pin 3 -> Arduino Uno pin 0
ATTINY85/45 pin 4 -> Arduino Uno pin 1

Basically uses the Arduino's brains to for serial communication.

Don't forget burn the bootloader and to set at 8 MHz!

 */


#include <SoftwareSerial.h>
// Definitions
#define rxPin 3
#define txPin 4

SoftwareSerial mySerial(rxPin, txPin);

int sensorPin = 7; //ACTUALLY PIN LABELED AS "2" on the HLT tutorial



// the setup routine runs once when you press reset:
void setup() {                
  pinMode(sensorPin, INPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
}

// the loop routine runs over and over asensorpingain forever:
void loop() {

  int sensorVal = analogRead(sensorPin); 
  mySerial.println("Input Val: ");
  mySerial.println(sensorVal);

  mySerial.println();
}

