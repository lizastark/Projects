/*
  Analog Tilt  Sensor
  October 2018
  http://thesoftcircuiteer.net/soft-sensors/
  Liza Stark 

  This sketch uses smoothing, constrain, and mapping to read a fabric
  pressure sensor built with Eeontex and conductive fabric.

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

//LED brightness values
int padOne = 5;
int padTwo = 30;
int padThree = 90;
int padFour = 255;

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

//these if statements determine which "pad" is activated
//change these numbers based on your own readings
  if (average >= 180 && average <= 200) {

    //write the new value to the LED
    analogWrite(ledPin, padOne);
    analogWrite(ledPin2, padOne);
    analogWrite(ledPin3, padOne);
    Serial.println("Pad 1 activated");
    
  } else if (average >= 146 && average <= 160) {

    //write the new value to the LED
    analogWrite(ledPin, padTwo);
    analogWrite(ledPin2, padTwo);
    analogWrite(ledPin3, padTwo);
    Serial.println("Pad 2 activated");
  
  } else if (average >= 250 && average <= 270) {

    //write the new value to the LED
    analogWrite(ledPin, padThree);
    analogWrite(ledPin2, padThree);
    analogWrite(ledPin3, padThree);
    Serial.println("Pad 3 activated");
    
  } else if (average >= 280 && average <= 315) {

    //write the new value to the LED
    analogWrite(ledPin, padFour);
    analogWrite(ledPin2, padFour);
    analogWrite(ledPin3, padFour);
    Serial.println("Pad 4 activated");
    
  } else {
    analogWrite(ledPin, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    Serial.println("Off");
    
  }
  delay(1);        // delay in between reads for stability

}
