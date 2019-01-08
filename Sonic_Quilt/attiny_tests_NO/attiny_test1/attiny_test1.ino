/*
 * By WK
 * http://cyaninfinite.com/projects/playing-music-tracks-with-df-robot-mp3-player-module/
 * 
 * Checklist:
 *    Why do these commands work when mine don't?
 *    Need to integrate with sensors
 *    try setting volume separately in setup and removing from function
 * 
 */


#include "SoftwareSerial.h"

 
//MP3 Settings
SoftwareSerial mySerial(10, 9);
# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 //Returns info with command 0x41 [0x01: info, 0x00: no info]
 
void setup() {

  //MP3
  mySerial.begin(9600);
  delay(1000);
  playFirst(); // putting this in the loop causes it to reset - something with the delay?
 
}
 
 
//uint8_t i = 0;
//short int t = 30;
 
void loop() {
  playNext();
  
  /*
    //Get vol
    execute_CMD(0x43, 0, 0);
    delay(500);
    while (mySerial.available() > 0) {
    oled.print(mySerial.read());
    oled.print(" ");
    }
  */

  /*
  playNext();
  t = 30;
  if (i < 2) {
    i++;
  } else {
    i = 0;
  }
  */
}
 
void playFirst()
{
  execute_CMD(0x3F, 0, 0);
  delay(500);
  setVolume(20);
  delay(500);
  execute_CMD(0x11, 0, 1);
  delay(500);
  mySerial.println("Track 1");
}

 /*
void pause()
{
  execute_CMD(0x0E, 0, 0);
  delay(500);
}
 
void play()
{
  execute_CMD(0x0D, 0, 1);
  delay(500);
}

 */
void playNext()
{
  execute_CMD(0x01, 0, 1);
  //delay(500);
  mySerial.println("Track 2");
}

 /*
void playPrevious()
{
  execute_CMD(0x02, 0, 1);
  delay(500);
}
  */
void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(2000);
}

void execute_CMD(byte CMD, byte Par1, byte Par2)
// Excecute the command and parameters
{
  // Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
  // Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
                            Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte
                          };
  //Send the command line to the module
  for (byte k = 0; k < 10; k++)
  {
    mySerial.write( Command_line[k]);
  }
}

