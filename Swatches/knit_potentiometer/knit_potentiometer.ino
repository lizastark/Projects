/*

  Knit Potentiometer
  October 2018
  http://thesoftcircuiteer.net/soft-sensors/
  Liza Stark 

  This sketch reads the data coming in from the
  sensor, maps it to a usable range, and writes
  the new value to an LED.

  map(value, fromLow, fromHigh, toLow, toHigh)
  https://www.arduino.cc/en/Reference/Map


*/

int sensorPin = A1;    // select the input pin for the potentiometer
int ledPin = 9;     // select the pin for the LED
int ledPin2 = 10;     // select the pin for the LED
int ledPin3 = 11;    // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int newSensorValue;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("SensorValue = ");
  Serial.print(sensorValue);
  Serial.print("\t");

  //map the values to something usable
  //map(value, fromLow, fromHigh, toLow, toHigh)
  newSensorValue = map(sensorValue, 958, 1023, 0, 255);

  //keep the LED low or off if we get a value less than 1
  if (newSensorValue < 1) {
    analogWrite(ledPin, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
  } else if (newSensorValue >= 1) {

    //write the new value to the LED
    analogWrite(ledPin, newSensorValue);
    analogWrite(ledPin2, newSensorValue);
    analogWrite(ledPin3, newSensorValue);
  }
  //print the new value to the serial monitor
  Serial.print("newSensorValue = ");
  Serial.println(newSensorValue);

  delay(10);

}
