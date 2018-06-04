/*
   DFPLAYER MINI SENSOR TEST (with functions)
   Sonic Quilt Project 
   May 16, 2018
   Liza Stark
   
   Reading patch sensor values with smoothing. Determines when both sensors have
   crossed a threshold, then plays audio file from DFPlayer Mini.

   Define the number of samples to keep track of. The higher the number,
   the more the readings will be smoothed, but the slower the output will
   respond to the input.  Using a constant rather than a normal variable lets
   use this value to determine the size of the readings array.

   The left sensor is attached to A0
   The right sensor is attached to A2

   Very important: Use serial 1K resistors on RX and TX
   to suppress noise
   Connect Sound module board RX to Arduino pin 8
   Connect Sound module board TX to Arduino pin 9

   Attribution:
   Incorporates Arduino smoothing example by Mellis and Igoe:
   https://www.arduino.cc/en/Tutorial/Smoothing

   Sensor threshold crossing code based on examples from ITP Lab on sensor change
   detection:
   https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/lab-sensor-change-detection/

   DFPlayer Mini code adapted from Ype Brada's amazing work. Documentation here:
   https://forum.banggood.com/forum-topic-59997.html


*/




#include "SoftwareSerial.h"
SoftwareSerial mySerial(8, 9);


char playFile[10] = { 0X7E, 0xFF, 0x06, 0X03, 00, 00, 0x01, 0xFE, 0xF7, 0XEF}; // Array to store the command to play audio file
char stopFile[10] = { 0X7E, 0xFF, 0x06, 0X16, 00, 00, 0x00, 0xFE, 0xE5, 0XEF};
char setVolume[10] = { 0X7E, 0xFF, 0x06, 0X06, 00, 00, 0x1E, 0xFE, 0xD7, 0XEF}; // Array to store the command to set the volume to 30

const int numReadings = 10;     // Same for both

int lastSensorStateLeft = LOW;  // Store left sensor state
int lastSensorStateRight = LOW; // Store left sensor state

//Peak detection variables
//int peakValueLeft = 0;
//int peakValueRight = 0;

int leftSensor = A0;            // L input pin
int rightSensor = A2;           // R input pin

int readingsLeft[numReadings];  // the readings from the left sensor
int readingsRight[numReadings]; // the readings from the right sensor



/* SENSOR THRESHOLD VARIABLES FOR EACH PATCH 
*  Comment out for each speaker
*/

//Speaker 1 - DONE - UPLOADED
//int thresholdLeft = 300;         // Left quilt patch opened
//int thresholdRight = 297;        // Right quilt patch opened

//Speaker 2 - DONE
//int thresholdLeft = 298;         // Left quilt patch opened
//int thresholdRight = 270;        // Right quilt patch opened

//Speaker 3 - DONE
//int thresholdLeft = 273;         // Left quilt patch opened
//int thresholdRight = 276;        // Right quilt patch opened

//Speaker 4 - SEE OTHER SKETCH

//Speaker 6 - DONE
//int thresholdLeft = 304;         // Left quilt patch opened
//int thresholdRight = 285;        // Right quilt patch opened

//Speaker 7 - DONE
int thresholdLeft = 257;         // Left quilt patch opened
int thresholdRight = 271;        // Right quilt patch opened

//Speaker 8 - DONE
//int thresholdLeft = 283;         // Left quilt patch opened
//int thresholdRight = 269;        // Right quilt patch opened

//Speaker 9 - SEE OTHER SKETCH

/* END SENSOR VARIABLES */



int readIndexLeft = 0;          // the index of the current reading on the left sensor
int readIndexRight = 0;         // the index of the current reading on the right sensor

int totalLeft = 0;              // the running total for the left sensor
int totalRight = 0;             // the running total for the right sensor

int averageLeft = 0;            // the average for the left sensor
int averageRight = 0;           // the average for the right sensor



void setup () {
  Serial.begin(9600);
  mySerial.begin (9600);

  delay(1000); // Need a delay for initializing parameters

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // initialize all the readings on the LEFT sensor to 0:
  for (int thisReadingLeft = 0; thisReadingLeft < numReadings; thisReadingLeft++) {
    readingsLeft[thisReadingLeft] = 0;
  }
  // initialize all the readings on the RIGHT sensor to 0:
  for (int thisReadingLeft = 0; thisReadingLeft < numReadings; thisReadingLeft++) {
    readingsLeft[thisReadingLeft] = 0;
  }

  // Set volume to 30
  for (int count = 0; count < 10; count++) {
    mySerial.write(setVolume[count]);
  }
}

void loop () {

  // Calculate the average of the left sensor:
  averageLeft = readLeftSensor();

  // calculate the average:
  averageRight = readRightSensor();

  // send it to the computer as ASCII digits
 /*
  Serial.print("Left sensor = ");
  Serial.print(averageLeft);
  Serial.print("\t");
  Serial.print("Right sensor = ");
  Serial.print(averageRight);
  Serial.print("\t");
  delay(1);        // delay in between reads for stability
*/
  //If either sensor is opened (i.e. above threshold)
  if ((averageLeft >= thresholdLeft) || (averageRight >= thresholdRight)) {
    //check that both previous values were below threshold:
    if ((lastSensorStateLeft < thresholdLeft) && (lastSensorStateRight < thresholdRight)) {
      //at least one sensor is opened and crossed the threshold
      //play the file
      playAudioFile();
     // Serial.print("Patch OPEN");
    }
    //if both sensors are closed
  } else if ((averageLeft <= thresholdLeft) && (averageRight <= thresholdRight)) {
    //stop playing file
    stopAudioFile();
   // Serial.print("Patch CLOSED");
  }

//  Serial.println();

  //save states for next comparison
  lastSensorStateLeft = averageLeft;
  lastSensorStateRight = averageRight;

  delay(100);





}

int readLeftSensor() {

  // LEFT SENSOR
  // subtract the last reading:
  totalLeft = totalLeft - readingsLeft[readIndexLeft];  // read from the sensor:
  readingsLeft[readIndexLeft] = analogRead(leftSensor); // add the reading to the total:
  totalLeft = totalLeft + readingsLeft[readIndexLeft];  // advance to the next position in the array:
  readIndexLeft = readIndexLeft + 1;


  if (readIndexLeft >= numReadings) {   // if we're at the end of the array...
    readIndexLeft = 0;                  // ...wrap around to the beginning
  }

  // calculate the average:
  int average = totalLeft / numReadings;
  return average;
  
}

int readRightSensor(){
   
   // RIGHT SENSOR
  // subtract the last reading:
  totalRight = totalRight - readingsRight[readIndexRight]; // read from the sensor:
  readingsRight[readIndexRight] = analogRead(rightSensor); // add the reading to the total:
  totalRight = totalRight + readingsRight[readIndexRight]; // advance to the next position in the array:
  readIndexRight = readIndexRight + 1;

  if (readIndexRight >= numReadings) {  // if we're at the end of the array...
    readIndexRight = 0;                 // ...wrap around to the beginning:
  }

  // calculate the average:
  int average = totalRight / numReadings;
  return average;
  
}

void playAudioFile() {
  for (int count = 0; count < 10; count++) {
    mySerial.write( playFile[count]);
  }
}

void stopAudioFile() {
  for (int count = 0; count < 10; count++) {
    mySerial.write( stopFile[count]);
  }
}


