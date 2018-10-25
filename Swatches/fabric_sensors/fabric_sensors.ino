/*
  Fabric Sensors
  October 2018
  http://thesoftcircuiteer.net/soft-sensors/
  Liza Stark 

  This sketch uses smoothing, constrain, and mapping to read a fabric
  pressure sensor built with pressure sensitve fabric (such as Eeontex
  or Velostat) and conductive fabric. Use this for pressure, stretch, 
  bend, and potentiometer sensors.

  It uses the smoothing example that reads repeatedly from an analog 
  input, calculating a running average and printing it to the 
  computer. Keeps ten readings in an array and continually
  averages them.

  It then constrains that value, then maps it to a usable range, 
  and writes the new value to an LED.

  Smoothing example
  http://www.arduino.cc/en/Tutorial/Smoothing

  constrain(value, min, max);
  
  map(value, fromLow, fromHigh, toLow, toHigh)
  https://www.arduino.cc/en/Reference/Map
*/

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A1;
int ledPin = 9;     // select the pin for the LED
int ledPin2 = 10;     // select the pin for the LED
int ledPin3 = 11;    // select the pin for the LED

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.print("Unmapped readings = ");
  Serial.print(average);
  
  Serial.print("\t");

  //change these numbers to the min and max you want to use
  average = constrain(average, 600, 1000);

  //map the average onto a range the LEDs can use
  int newAverage = map(average, 600, 1000, 0, 255);

  //print it out for debugging
  Serial.print("Mapped readings = ");
  Serial.println(newAverage);

  //constrain the new average again just in case
  newAverage = constrain(newAverage, 0, 255);

  if (newAverage < 1) {
    analogWrite(ledPin, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
  } else if (newAverage >= 1) {

    //write the new value to the LED
    analogWrite(ledPin, newAverage);
    analogWrite(ledPin2, newAverage);
    analogWrite(ledPin3, newAverage);
  }
  delay(1);        // delay in between reads for stability

}
