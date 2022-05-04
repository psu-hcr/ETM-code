/*
*Quadrature Encoder Starter Code
*Code Inspired by: http://yameb.blogspot.com/2012/11/quadrature-encoders-in-arduino-done.html
*/
#include "Arduino.h"

//Setting up interrupt pins
#define EncoderInterruptA 0
#define EncoderInterruptB 1
#define EncoderPinA 2 //Must be pin 2 (Only pin 2 and 3 are interrupt pins)
#define EncoderPinB 3 //Must be pin 3

//Defines variables for pin states
volatile bool EncoderASet;
volatile bool EncoderBSet;
volatile bool EncoderAPrev;
volatile bool EncoderBPrev;

volatile long EncoderTicks = 0; //Initializing Tick COunter
float MotorCPR = 542; //CHANGE TO CORRECT CPR

void setup()
{
  Serial.begin(115200); //Baudrate: Change as needed

  pinMode(EncoderPinA, INPUT);      // sets pin A as input
  digitalWrite(EncoderPinA, LOW);  // turn on pullup resistors
  pinMode(EncoderPinB, INPUT);      // sets pin B as input
  digitalWrite(EncoderPinB, LOW);  // turn on pullup resistors
  attachInterrupt(digitalPinToInterrupt(EncoderPinA), HandleMotorInterruptA, CHANGE); //Setting up first interrupt
  attachInterrupt(digitalPinToInterrupt(EncoderPinB), HandleMotorInterruptB, CHANGE); //Setting up second interrupt
}

void loop()
{ 
  Serial.print("Encoder Ticks: ");
  Serial.print(EncoderTicks); //Counted Ticks
  Serial.print("  Revolutions: ");
  Serial.print(EncoderTicks/MotorCPR);  //4000 Counts Per Revolution //CHANGE TO CORRECT CPR
  Serial.print("\n");
}


// Interrupt service routine for Channel A
void HandleMotorInterruptA(){
  //Read Encoder Pins
  EncoderBSet = digitalRead(EncoderPinB);
  EncoderASet = digitalRead(EncoderPinA);
  
  EncoderTicks+=ParseEncoder(); //either incremensts encoder up or down

  //Stores previous encoder value
  EncoderAPrev = EncoderASet;
  EncoderBPrev = EncoderBSet;
}

// Interrupt service routine for Channel B
void HandleMotorInterruptB(){
  //Read Encoder Pins
  EncoderBSet = digitalRead(EncoderPinB);
  EncoderASet = digitalRead(EncoderPinA);
  
  EncoderTicks+=ParseEncoder(); //either incremensts encoder up or down

  //Stores previous encoder value
  EncoderAPrev = EncoderASet;
  EncoderBPrev = EncoderBSet;
}

//Checks if count needs to go up or down based off previous and current states of channels
int ParseEncoder(){
  if(EncoderAPrev && EncoderBPrev){
    if(!EncoderASet && EncoderBSet) return 1;
    if(EncoderASet && !EncoderBSet) return -1;
  }else if(!EncoderAPrev && EncoderBPrev){
    if(!EncoderASet && !EncoderBSet) return 1;
    if(EncoderASet && EncoderBSet) return -1;
  }else if(!EncoderAPrev && !EncoderBPrev){
    if(EncoderASet && !EncoderBSet) return 1;
    if(!EncoderASet && EncoderBSet) return -1;
  }else if(EncoderAPrev && !EncoderBPrev){
    if(EncoderASet && EncoderBSet) return 1;
    if(!EncoderASet && !EncoderBSet) return -1;
  }
}
