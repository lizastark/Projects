
/*
 * At the Fringes
 * eTextile Swatchbook Exchange 2017
 * 
 * Full documentation link:
 * 
 * This swatch allows us to access three buttons on one analog pin 
 * of the ATtiny 45/85.  When you usually read a button on a 
 * digital pin, closing the button will send 5 volts to the pin 
 * telling the micro controller it is closed. On or off. On an 
 * analog pin, we can read a range of values between 0 and 1023 
 * or 0 volts and 5 volts. By connecting different values of 
 * resistors to buttons on an analog pin, we can tell the ATtiny 
 * to read a button press as a range of values instead of on or 
 * off. This means we can connect many buttons to just one pin 
 * and use conditional statements to determine  if a button was 
 * pressed. Or a ribbon was pulled in this case.
 * 
 * I used a 1k, 3k, and 5k resistor for the three buttons, 
 * with one lead to power and the other the button.
 * 
 * Use the softwareSerial_ATtiny sketch and fritzing diagram in the 
 * documentation link to read your values once you have 
 * constructed your fabric PCB and switches.
 *
 *                  attiny85/45
 *              reset -+---+- power
 *    (sensor pin A3) -+*  +- pb2 (right LED) 
 *                    -+   +- pb1 (middle LED)
 *             ground -+---+- pb0 (left LED)
 *             
 *  Note: In this version, we are reading values reversed from 
 *  what you would expect. Instead of checking the values for
 *  when a switch is closed, we read for when they are open. 
 *  This tended to work better for some of the swatches than others.
 *  See the fringeSwatch_v1_HIGH sketch for the alternate code in the 
 *  documentation link.
 *  
 */

int sensorPin = A3; //Reads resistor ladder
int sensorVal; //Value to store sensor reading

int ribbon1 = 2; //Controls left LED
int ribbon2 = 1; //Controls middle LED
int ribbon3 = 0; //Controls right LED

void setup() {

  pinMode(sensorPin, INPUT);

  pinMode(ribbon1, OUTPUT);
  pinMode(ribbon2, OUTPUT);
  pinMode(ribbon3, OUTPUT);

}

void loop() {

  //read the sensor
  sensorVal = analogRead(sensorPin);

  //all ribbons open
  if (sensorVal == 0) {

    //turn off all LEDs
    digitalWrite(ribbon1, LOW);
    digitalWrite(ribbon2, LOW);
    digitalWrite(ribbon3, LOW);

  }

  //left ribbon open
  //middle and right ribbon closed
  else if (sensorVal >= 858 && sensorVal <= 870) {

    //turn off ribbon1
    digitalWrite(ribbon1, LOW);

    //turn on ribbon 2 & 3
    digitalWrite(ribbon2, HIGH);
    digitalWrite(ribbon3, HIGH);

  }

  //middle ribbon open
  //left and right ribbon closed
  else if (sensorVal >= 943 && sensorVal <= 947) {

    //turn off ribbon2
    digitalWrite(ribbon2, LOW);

    //turn on ribbon 1 & 3
    digitalWrite(ribbon1, HIGH);
    digitalWrite(ribbon3, HIGH);

  }

  //right ribbon open
  //middle and left ribbon closed
  else if (sensorVal >= 951 && sensorVal <= 959) {

    //turn off ribbon3
    digitalWrite(ribbon3, LOW);

    //turn on ribbon 1 & 2
    digitalWrite(ribbon1, HIGH);
    digitalWrite(ribbon2, HIGH);

  }

  //left and middle ribbon open
  //right ribbon closed
  else if (sensorVal >= 670 && sensorVal <= 690) {

    //turn off ribbon 1 & 2
    digitalWrite(ribbon1, LOW);
    digitalWrite(ribbon2, LOW);

    //turn on ribbon 3
    digitalWrite(ribbon3, HIGH);

  }

  //middle and right ribbon open
  //left ribbon closed
  else if (sensorVal >= 930 && sensorVal <= 936) {

    //turn off ribbon 2 & 3
    digitalWrite(ribbon2, LOW);
    digitalWrite(ribbon3, LOW);

    //turn on ribbon 1
    digitalWrite(ribbon1, HIGH);

  }

  //left and right ribbon open
  //middle ribbon closed
  else if (sensorVal >= 700 && sensorVal <= 800) {

    //turn off ribbon 1 & 3ß
    digitalWrite(ribbon1, LOW);
    digitalWrite(ribbon3, LOW);

    //turn on ribbon 2
    digitalWrite(ribbon2, HIGH);

  }

  //all ribbons are closed
  else if (sensorVal >= 960 && sensorVal <= 970) {

    //turn on off LEDs
    digitalWrite(ribbon1, HIGH);
    digitalWrite(ribbon2, HIGH);
    digitalWrite(ribbon3, HIGH);

  }


}
