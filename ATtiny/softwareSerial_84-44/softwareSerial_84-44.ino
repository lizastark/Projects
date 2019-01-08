/*

   Software Serial with the ATtiny

   This sketch reads analog values coming in from the ATtiny.
   Be sure to read the full pinout when working with analog input:
   http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png

   Fall 2016
   Computational Craft //MFADT Parsons

   CREDITS:
  quitmeyer
  https://github.com/quitmeyer/ATtinyBareDemos/blob/master/ATTinyAnalogInputTOSerial/ATTinyAnalogInputTOSerial.ino

  Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)
  and outputs these with Software serial to the arduino uno, or Duemillanove
  Hookup
  ATTINY85/45 pin 3 -> Arduino Uno pin 0
  ATTINY85/45 pin 4 -> Arduino Uno pin 1

*/


#include <SoftwareSerial.h>
// Definitions
#define rxPin 10 //3
#define txPin 9 //4

int led = 3;
int sensorPin = A2; //uncomment if using ATtiny 44/84
int sensorVal = 0;

SoftwareSerial mySerial(rxPin, txPin);


// the setup routine runs once when you press reset:
void setup() {
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

// the loop routine runs over and over asensorpingain forever:
void loop() {

  sensorVal = analogRead(sensorPin);
  mySerial.print("Input Val: ");
  mySerial.print(sensorVal);
  mySerial.println();

  analogWrite(led, sensorVal);

  /*
    digitalWrite(led, HIGH);
    mySerial.println("ON");
    delay(1000);
    digitalWrite(led, LOW);
    mySerial.println("OFF");
    delay(1000);
  */
}

