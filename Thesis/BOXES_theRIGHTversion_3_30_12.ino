
/*
 
 BOXES
 Building Open Expandable Electronic Systems
 (For the ATtiny 44)
 
 MFA Design + Technology Thesis
 
 Liza Stark
 March 30, 2012
 (With the gracious aid of Chris Piuggi)
 
 When one switch is closed, the LED fades very slowly.
 When two switches are closed, the LED blinks at a slow pace.
 When three switches are closed, the LED fades in and out quickly.
 When four switches are closed, the LED blinks very rapidly.
 If no sides are closed, the box is off.
 
 
 */
 
 

int side[] = {
  //6,7,8,9}; //Arduino
  0,9,6,2}; //ATtiny84

int val[] = {
  0,0,0,0};

int total;

//int ledPin = 10; //Arduino
int ledPin = 8; //ATtiny84


void setup(){

  for(int i=0;i<4;i++){
    pinMode(side[i], INPUT);
  }

  pinMode(ledPin, OUTPUT);

  //Serial.begin(9600);

}

void loop(){

  for(int i=0; i<4; i++){
    val[i] = digitalRead(side[i]);
  }

  for(int i=0; i<4; i++){
    total += val[i];
  }

  //Serial.println(total);

  if(total == 0){
    asleep();
    //analogWrite(ledPin, 50);
  }

  else if(total == 1){
    breathe();
    //analogWrite(ledPin, 100);
  }

  else if(total == 2){
    talk();
    //analogWrite(ledPin, 150);
  }

  else if(total == 3){
    yell();
    //analogWrite(ledPin, 200);
  }

  else if(total == 4){
    chaos();
    //analogWrite(ledPin, 250);
  }

  total = 0;

}



//NO SIDES
void asleep(){
  digitalWrite(ledPin, LOW); 
}

//ONE SIDE
void breathe(){
  int valBreathe=0; 
  long time=0;
  int period = 500; 

  time = millis();
  valBreathe = 128+127*cos(2*PI/period*time);

  analogWrite(ledPin, valBreathe);           // sets the value (range from 0 to 255)

}

//TWO SIDES
void talk(){
  digitalWrite(ledPin, HIGH);
  delay(30);
  digitalWrite(ledPin, LOW);
  delay(30);

}

//THREE SIDES
void yell(){
  int valYell=0; 
  long time=0;
  int period = 150; 

  time = millis();
  valYell = 128+127*cos(2*PI/period*time);

  analogWrite(ledPin, valYell);           // sets the value (range from 0 to 255)


}


//FOUR SIDES
void chaos(){
  digitalWrite(ledPin, HIGH);
  delay(12);
  digitalWrite(ledPin, LOW);
  delay(12);

}




