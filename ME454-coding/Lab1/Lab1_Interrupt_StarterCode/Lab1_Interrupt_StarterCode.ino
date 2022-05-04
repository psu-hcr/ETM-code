//Lab 01 Interrupt Starter Code
//August 2021
//Author: Sasha
/*This code uses an interrupt procedure to read the digital value of a signal when it changes states
 */

//Pin Assignment
const byte interruptPin = 3; //Assign pin 2 as interruptPin (only pin 2 and pin 3 have interrupt functionality)

//Timing Variable
unsigned long currentTime = 0; //variable to indicate current time


void setup() {
//  pinMode(readPin, INPUT); //Setting read pin as an input
  pinMode(interruptPin, INPUT); //sets interruptPin as an input 
  Serial.begin(115200); //Initializing serial communication (high baudrate allows for faster communication with arduino)
  attachInterrupt(digitalPinToInterrupt(interruptPin), read, CHANGE); //setup interrupt procedure to be triggered by change in interruptPin state (both HIGH to LOW and LOW to HIGH)
}

void loop() {
  currentTime = millis(); //measure and save current time
}

void read() {
  Serial.print(currentTime); //print last saved current time
  Serial.print(", ");
  Serial.println(digitalRead(interruptPin)); //print interruptPin state
}
