// Lab05 Task01 Starter Code
// September 2021
// Author: Xinyu
// 
/*
*The code used a polling loop to periodically read the value of an analog sensor
*/
//Pin Assignment
const int sensorPin = A0; // pin to which the proximity sensor is connected to
 

// Define time variables
unsigned long startTime = 0;  
unsigned long currentTime;  
unsigned long elapsedTime; 
unsigned long samplingTime = 10; //minimum elapsed time (in millisecond) before we sample (poll) again


// Define other variables
double sensorVal = 0; // a variable where the sensor value is stored 
double voltageVal = 0.0; // a variable where the voltage value is stored
int count = 0; // the index of data points you are printing
int totalCounts = 5; // the number of data points you want to print


// TO BE DONE: DEFINE VARIABLES FOR DIGITAL FILTER


void setup() {
  Serial.begin(115200); // set the baud rate to 115200
  delay(100); // wait for sensor initialization
 
}

void loop() {
  //polling loop 
  if (count < totalCounts) { // use if statement to print "totalCounts" data points
    currentTime = millis(); // get the current time
    elapsedTime = currentTime - startTime; // calculate the elapsed time
    // reads the sensor value every samplingTime milliseconds
    if (samplingTime <= elapsedTime) { //check if it's time to poll again
        sensorVal = analogRead(sensorPin); // reads the sensor value
        // CHOOSE CORRECT VALUE FOR "X" AND "V"
        voltageVal = (sensorVal/2)*3; // convert reading value back to voltage value
        // TO BE DONE: IMPLEMENT YOUR DIGITAL FILTER
        
        Serial.print(currentTime); // print current time
        Serial.print(", ");
        Serial.println(voltageVal); // prints the voltage value to the serial monitor
        count ++; // update the index for the next data point
        startTime = millis();
    }
  } // end polling loop   
}
