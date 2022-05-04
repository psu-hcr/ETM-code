//Lab 01 Polling Starter Code
//August 2021
//Author: Sasha
/*This code uses a polling loop to periodically read the digital value of a signal
 */

//Pin Assignment
const int readPin = 3; //Pin assignment for reading signal

//Timing Variables
unsigned long startTime = 0;
unsigned long currentTime = 0;
unsigned long elapsedTime;

const int samplingTime = 5; //minimum elapsed time before we sample (poll) again

//Variables
int reading; //value of digital read (whether signal that we are measuring is high or low)

void setup() {
  pinMode(readPin, INPUT); //Setting read pin as an input
  Serial.begin(115200); //Initializing serial communication (high baudrate allows for faster communication with arduino)
}

void loop() {
  currentTime = millis(); //check current time in microseconds
  elapsedTime = currentTime - startTime; //check time since last recorded poll time in microseconds

  //Polling loop
  if (samplingTime <= elapsedTime) { //check if it's time to poll again
    reading = digitalRead(readPin); //read the pin connected to the signal
    //THIS PRINTS EVERY TIME WE POLL. 
    Serial.print(currentTime); //print current time
    Serial.print(", ");
    Serial.println(reading); //print reading
    startTime = millis(); //record time from which to wait another sampingTime (or, more precisely, the first time we measure elapsedTime to be greater than samplingTime) milliseconds before polling again
  } //end polling loop
}
