  
/*
 * Data Vows
 * by Liza Stark + John Keefe
 *
 * This sketch takes data coming in from a Polar One Heartrate monitor (from Adafruit)
 * and counts the number of beats per minute. It takes a sample every 15 seconds
 *
 *
 */

unsigned long checkTime = 15000;

int oldSample;
int newSample;

int beatCount; // value that store the number of heart beats
//How many samples taking
int beatsPerMin;

int dressFadeValue = 5;
int dressFadeStart = 5; // this helps smooth out when we start things off


const int HR_RX = 0; /// NEED TO CHANGE TO 2

int redPin = 10; // RED LED 
int greenPin = 9; // ORANGE LED
int bluePin = 6; // YELLOW LED

// Program variables set as integer (number) type
int redLEDValue = 255; // Variables to store the values to send to the pins
int greenLEDValue = 1; // Initial values are Red full, Green and Blue off
int blueLEDValue = 1; // These values get passed to the analogWrite() function.

int i; // Loop counter - this will be set to

void setup() {
  // put your setup code here, to run once:

  oldSample = 0; // need a variable to reset the sample, otherwise it would
  // just keep incrementing from the old sample
  beatCount = 0; // need a variable to reset the beatCount after we take our
  // our 15 second sample

  pinMode(redPin, OUTPUT); // sets the pins as output
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // this interrupt is constantly listening for a heartbeat on the same pin as the receiver module
  // when it hears one, it increases the value of beatCount by 1
  attachInterrupt(2, beatIncrement, RISING);

}

void loop() {
  // start listening for heartbeats by setting up a new sample
  newSample = digitalRead(HR_RX);

  // take a sample of heartbeats every 15 seconds
  if (millis()  > checkTime) {
    //see if it's been 15 seconds

    beatsPerMin = (beatCount * 4);
    // translate into how many beats per minute
    // 15 seconds in a minute, so times beatCount reading by 4

    Serial.print("beatCount = ");
    Serial.println(beatCount);

    // check for no beatCount ... if it's zero, make it 5 (really low)
    if (beatCount < 5) {
      beatCount = 5;
    }

    // send your beatCount to control the speed of LEDs fading
    dressFadeValue = beatCount;
    // map dressfadevalue here

    beatCount = 0; //
    checkTime = millis() + 15000; // gives us a way to know if 15 seconds has elapsed
  }

  /*
   Serial.print("millis: ");
   Serial.print(millis());
   Serial.print(" oldtime: ");
   Serial.print(oldTime);
   Serial.print(" beats: ");
   Serial.println(beatCount);
  */

  oldSample = newSample;


  i += dressFadeStart; // Increment counter - IDEALLY THE DATA WILL CONTROL THIS NUMBER

    Serial.print(redLEDValue);
    Serial.print(" ");
    Serial.print(greenLEDValue);
    Serial.print(" ");
    Serial.println(blueLEDValue);

  
  Serial.println(i);
  if (i < 255) { // First phase of fades
    redLEDValue -= 1; // Red down
    greenLEDValue += 1; // Green up
    blueLEDValue = 1; // Blue low
  }
  else if (i < 509) { // Second phase of fades
    redLEDValue = 1; // Red low
    greenLEDValue -= 1; // Green down
    blueLEDValue += 1; // Blue up
  }
  else if (i < 763) { // Third phase of fades
    redLEDValue += 1; // Red up
    greenLEDValue = 1; // Green low
    blueLEDValue -= 1; // Blue down
  }
  else {
    // Re-set the counter, and start the fades again
    i = 1;
    dressFadeStart = dressFadeValue;

    
  }

  // analogWrite() expects 2 parameters, the object/pin and a value between 0 (off) and 255 (full on)
  analogWrite(redPin, redLEDValue); // Write current values to LED pins
  analogWrite(greenPin, greenLEDValue);
  analogWrite(bluePin, blueLEDValue);

  delay(50); // Pause for xx milliseconds before resuming the loop
}

void beatIncrement() {
  beatCount++; //increment
}

