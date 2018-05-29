/*Dfminiplayer via commands, connecting six pins with six seperate tracks. Sets volume and then plays
 * when page(button is pressed)
 */
#include <Bounce2.h>
#include "SoftwareSerial.h"

SoftwareSerial mySerial(4, 7);

char play1[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x01, 0xFE, 0xF7, 0XEF};
char play2[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x02, 0xFE, 0xF6, 0XEF};
char play3[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x03, 0xFE, 0xF5, 0XEF};
char play4[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x04, 0xFE, 0xF4, 0XEF};
char play5[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x05, 0xFE, 0xF3, 0XEF};
char play6[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x06, 0xFE, 0xF2, 0XEF};

char stopFile1[10] = { 0X7E, 0xFF, 0x06, 0X16, 00, 00, 00, 0xFE, 0xE5, 0XEF};
char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x05, 0xFE, 0xF0, 0XEF}; //volume at 5
// char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x04, 0xFE, 0xF0, 0XEF}; //volume at 4
// char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x03, 0xFE, 0xF0, 0XEF}; //volume at 3
// char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x02, 0xFE, 0xF0, 0XEF}; //volume at 2
// char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x01, 0xFE, 0xF0, 0XEF}; //volume at 1

const int numReadings = 10;

//heating elements
#define sea 5
#define houses A1
#define train 6

// LED on
#define lanterns 2

int counter = 0;
   
#define PAGE_1 8  // buildings (sound. Heat)
#define PAGE_2 9  // window (sound. no heat)
#define PAGE_3 10  // Sea (sound. Heat)
#define PAGE_4 11 // tree input (silent page. no heat)
#define PAGE_5 12 // train (sound. Heat)
#define PAGE_6 13 // people (sound)
#define PAGE_7 12 // tent  (silent page. no heat)
#define PAGE_8 3 // candles (LED signal)

Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
Bounce debouncer5 = Bounce(); 
Bounce debouncer6 = Bounce();
Bounce debouncer7 = Bounce(); 
Bounce debouncer8 = Bounce();

void setup() {
  // put your setup code here, to run once:
  pinMode(PAGE_1,INPUT_PULLUP);
  debouncer1.attach(PAGE_1);
  debouncer1.interval(5); // interval in ms
  
  pinMode(PAGE_2,INPUT_PULLUP);
  debouncer2.attach(PAGE_2);
  debouncer2.interval(5); // interval in ms
  
  pinMode(PAGE_3,INPUT_PULLUP);
  debouncer3.attach(PAGE_3);
  debouncer3.interval(5); // interval in ms
  
  pinMode(PAGE_4,INPUT_PULLUP);
  debouncer4.attach(PAGE_4);
  debouncer4.interval(5); // interval in ms}
  
  pinMode(PAGE_5,INPUT_PULLUP);
  debouncer5.attach(PAGE_5);
  debouncer5.interval(5); // interval in ms
  
  pinMode(PAGE_6,INPUT_PULLUP);
  debouncer6.attach(PAGE_6);
  debouncer6.interval(5); // interval in ms}
   
  pinMode(PAGE_7,INPUT_PULLUP);
  debouncer7.attach(PAGE_7);
  debouncer7.interval(5); // interval in ms
  
  pinMode(PAGE_8,INPUT_PULLUP);
  debouncer8.attach(PAGE_8);
  debouncer8.interval(5); // interval in ms}
  
Serial.begin(9600);
mySerial.begin (9600);
 for (int count = 0; count < 10; count++) {
    mySerial.write( setVolume[count]);
  }
Serial.println ("Loading...");
delay(5000);
}

void loop() {
 debouncer1.update();
 debouncer2.update();
 debouncer3.update();
 debouncer4.update();
 debouncer5.update();
 debouncer6.update();
 debouncer7.update();
 debouncer8.update();

  int value1 = debouncer1.read();
  int value2 = debouncer2.read();
  int value3 = debouncer3.read();
  int value4 = debouncer4.read();

if (debouncer1.fell()
) {
    playFile1();
    Serial.println ("page 1 is on.");
    analogWrite(houses, 0);
    analogWrite(sea,0);
    analogWrite(train,0);
  for (int x = 0; x < 120; x++){analogWrite(houses, 255);
  delay (200);
  analogWrite (houses, 0);
  delay(200);
 } 
 analogWrite (houses, 0);}
   
if (debouncer2.fell()) {
  playFile2();
 Serial.println ("page 2 is on.");
   analogWrite(houses, 0);
    analogWrite(sea,0);
    analogWrite(train,0);
    }
    
if (debouncer3.fell()) {
  playFile3();
 Serial.println ("page 3 is on.");
   analogWrite(houses, 0);
   analogWrite(sea,0);
   analogWrite(train,0);
 for (int x = 0; x < 120; x++){analogWrite(sea, 255);
  delay (200);
  analogWrite (sea, 0);
  delay(200);
 }
 analogWrite(sea,0);}

if (debouncer4.fell()) {
  Stopall();
  Serial.println ("page 4 is on.");
  analogWrite(houses, 0);
  analogWrite(sea,0);
  analogWrite(train,0);
  }

  if (debouncer5.fell()) {
  playFile4();
 Serial.println ("page 5 is on.");
    analogWrite(houses, 0);
    analogWrite(sea,0);
    analogWrite(train,0);
  for (int x = 0; x < 120; x++){analogWrite(train, 255);
  delay (200);
  analogWrite (train, 0);
  delay(200);
 }
  analogWrite (train, 0);}  
    
  if (debouncer6.fell()) {
  playFile5();
 Serial.println ("page 6 is on.");
    analogWrite(houses, 0);
    analogWrite(sea,0);
    analogWrite(train,0);
   }
    if (debouncer8.fell()) {
  Stopall();
 Serial.println ("page 8 is on.");
 
    analogWrite(lanterns, 150);
    delay (15000);
    analogWrite(lanterns, 0);
    delay(500); }
  
}

void playFile1() {
  for (int count = 0; count < 10; count++) {
    mySerial.write(play1[count]);
    //Serial.println("file 1 played");
  }
}
void playFile2() {
  for (int count = 0; count < 10; count++) {
    mySerial.write(play2[count]);
    //Serial.println("file 2 played");
  }
}
void playFile3() {
  for (int count = 0; count < 10; count++) {
    mySerial.write(play3[count]);
    //Serial.println("file 3 played");
  } 
}
void playFile4() {
  for (int count = 0; count < 10; count++) {
    mySerial.write(play4[count]); 
    //Serial.println("file 4 played");
  }
}
void playFile5() {
  for (int count = 0; count < 10; count++) {
    mySerial.write(play5[count]); 
    //Serial.println("file 5 played");
  }
}
void playFile6() {
  for (int count = 0; count < 10; count++) {
    mySerial.write(play6[count]); 
    //Serial.println("file 6 played");
  }
}
  void Stopall(){
     for (int count = 0; count < 10; count++) {
    mySerial.write(stopFile1[count]); 
    Serial.println("no files played");
  }
  }  
