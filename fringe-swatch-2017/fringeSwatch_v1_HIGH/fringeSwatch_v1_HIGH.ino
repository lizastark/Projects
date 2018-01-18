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
 *  Note: In this version, we are reading values for when the switch 
 *  closed. Some swatches worked better reading values for when the 
 *  switch was open. See the fringeSwatch_v2_LOW sketch for the alternate code in the 
 *  documentation link.
 *  
 */

int sensorPin = A3;
int sensorVal;

int ribbon1 = 2;
int ribbon2 = 1;
int ribbon3 = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(sensorPin, INPUT);

  pinMode(ribbon1, OUTPUT);
  pinMode(ribbon2, OUTPUT);
  pinMode(ribbon3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorVal = analogRead(sensorPin);

  //all buttons open
  if (sensorVal == 0) {

    //turn on all LEDs
    digitalWrite(ribbon1, LOW);
    digitalWrite(ribbon2, LOW);
    digitalWrite(ribbon3, LOW);

  }

  //button 1 closed - ribbon1 pulled
  else if (sensorVal >= 928 && sensorVal <= 934) {

    //turn on ribbon1
    digitalWrite(ribbon1, HIGH);

    //turn off ribbon 2 & 3
    digitalWrite(ribbon2, LOW);
    digitalWrite(ribbon3, LOW);

  }

  //button 2 closed - ribbon 2 is pulled
  else if (sensorVal >= 785 && sensorVal <= 792) {

    //turn on ribbon2
    digitalWrite(ribbon2, HIGH);

    //turn off ribbon 1 & 3
    digitalWrite(ribbon1, LOW);
    digitalWrite(ribbon3, LOW);

  }

  //ribbon 3 is pulled
  else if (sensorVal >= 674 && sensorVal <= 682) {

    //turn on ribbon3
    digitalWrite(ribbon3, HIGH);

    //turn off ribbon 1 & 2
    digitalWrite(ribbon1, LOW);
    digitalWrite(ribbon2, LOW);

  }

  //ribbon 1 & 2 are pulled
  else if (sensorVal >= 949 && sensorVal <= 957) {

    //turn on ribbon 1 & 2
    digitalWrite(ribbon1, HIGH);
    digitalWrite(ribbon2, HIGH);

    //turn off ribbon 3
    digitalWrite(ribbon3, LOW);

  }

  //ribbon 2 & 3 are pulled
  else if (sensorVal >= 859 && sensorVal <= 865) {

    //turn on ribbon 2 & 3
    digitalWrite(ribbon2, HIGH);
    digitalWrite(ribbon3, HIGH);

    //turn off ribbon 1
    digitalWrite(ribbon1, LOW);

  }

  //ribbon 1 & 3 are pulled
  else if (sensorVal >= 942 && sensorVal <= 948) {

    //turn on ribbon 1 & 3ß
    digitalWrite(ribbon1, HIGH);
    digitalWrite(ribbon3, HIGH);

    //turn off ribbon 2
    digitalWrite(ribbon2, LOW);

  }

  //all ribbons are attached
  else if (sensorVal >= 959 && sensorVal <= 965) {

    //turn on off LEDs
    digitalWrite(ribbon1, HIGH);
    digitalWrite(ribbon2, HIGH);
    digitalWrite(ribbon3, HIGH);

  }


}
