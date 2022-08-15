// Lab 04 Starter Code
// September 2018

// Pin Assignments
int servo = 8;  // Assigns Pin 8 as the signal wire for the servo.
int led = 10;   // Assigns Pin 10 as the signal wire for the LED.

int width180_in_microseconds =0;     // Time width in microseconds for the 180 degree pulse. 
int width0_in_microseconds =0 ;     // Time width in microseconds for the 0 degree pulse. 

int width_ms_between_pulses = 20;      // Time width in milliseconds between pulses
int iterations = 500;  // Number of pulses sent through signal wire to servo.

int LEDbrightness = 0;  // Starting brightness of LED.
int LEDfadeAmount =10 ; // Increment at which the LED brightness varies.

void setup() {
  pinMode(servo,OUTPUT);  // Assigns the servo signal pin as an output.
  pinMode(led,OUTPUT);    // Assigns the LED signal pin as an output.
}

void loop() {
pulse0();                 // Sends PPM to go to 0 degrees.
pulse180();               // Sends PPM to go to 180 degrees.


analogWrite(led, LEDbrightness);    // Sets the LED to the current value of the brightness.
LEDbrightness += LEDfadeAmount;     // Updates the LED brightness.
if (0 >= LEDbrightness || 255 <= LEDbrightness) {
  LEDfadeAmount = -LEDfadeAmount;   // Negates the increment to reverse the brightness variation.
}
}


void pulse180() {                   // This function pulses a HIGH digital signal for "width180" milliseconds and a LOW digital signal for the remaining 20 milliseconds. Occurs "iterations" times. 
for(int count = 0; count <= iterations; count += 1){ // Iterates the loop "iterations" times.
  digitalWrite(servo,HIGH);         // Sets the servo pin as HIGH.
  delayMicroseconds(width180_in_microseconds);                  // Delays for the pulse time.
  digitalWrite(servo,LOW);          // Sets the servo pin as LOW.
  delay(width_ms_between_pulses);               // Delays for the remaining pulse time.
}
}


void pulse0() {                     // This function pulses a HIGH digital signal for "width0" milliseconds and a LOW digital signal for the remaining 20 milliseconds. Occurs "iterations" times. 
for(int count = 0; count <= iterations; count += 1) { // Iterates the loop "iterations" times.
  digitalWrite(servo,HIGH);         // Sets the servo pin as HIGH.
  delayMicroseconds(width0_in_microseconds);                    // Delays for the pulse time.
  digitalWrite(servo,LOW);          // Sets the servo pin as LOW.
  delay(width_ms_between_pulses);                 // Delays for the remaining pulse time.
}
}
