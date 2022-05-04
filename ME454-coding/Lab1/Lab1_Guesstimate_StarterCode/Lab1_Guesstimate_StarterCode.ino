//Lab 01 Guesstimate Starter Code
//August 2021
//Author: Sasha
/*This code uses a guesstimate timing to estimate time between changes in digital signal state
 */

//Pin Assignment
const int readPin = 3; //Pin assignment for reading signal

//Variables
int timeguess = 0; //variable that tells/guesses time
byte statenew; //current read state
byte stateold = 0; //state saved from last time
unsigned long wait = 10; //minimum wait time (in counts) before the time can be guessed again
unsigned long waitcount = 0; //incrementing count
const int timeincrement = 1; //time increment of loop

void setup() {
  pinMode(readPin, INPUT); //Setting read pin as an input
  Serial.begin(115200); //Initializing serial communication (high baudrate allows for faster communication with arduino)
}

void loop() {
  timeguess = timeguess+timeincrement; //adds roughly the time it takes to go through loop (in milliseconds) to our time guess)
  statenew = digitalRead(readPin);
  if((stateold != statenew && waitcount>wait)){ //checks if signal has changed states and has waited some minimum time
    Serial.print(timeguess); //prints time guess in milliseconds
    Serial.print(",  "); 
    Serial.println(statenew); //prints current signal state (HIGH or LOW)
    waitcount = 0; //resets waitcount
    stateold = statenew; //sets current state
  }
  else{
    waitcount = waitcount+1; //increments waitcount
  }
  delay(timeincrement); //helps us guess/keep time of code
}
