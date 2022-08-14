#include <RedBot.h>  
#include "SR04.h"
#define F_TRIG_PIN 11
#define F_ECHO_PIN 10
#define R_ECHO_PIN 3 
#define R_TRIG_PIN 9 

RedBotMotors motors; // Instantiate the motor control object.
SR04 R_sr04 = SR04(R_ECHO_PIN,R_TRIG_PIN);
SR04 F_sr04 = SR04(F_ECHO_PIN,F_TRIG_PIN);
long R_distance;
long F_distance;
long R_desire = 12;
long error;
long P = 2.0;

void setup()
{
  motors.brake();    // brake() motors
  delay(500);        // for 500 ms.
  Serial.begin(9600);
}

void loop()
{
  // read distance data
  R_distance = R_sr04.Distance();
  F_distance = F_sr04.Distance();
  Serial.print("F_Distance: ");
  Serial.print(F_distance);
  Serial.println(" cm");
  Serial.print("R_Distance: ");
  Serial.print(R_distance);
  Serial.println(" cm");

  if(F_distance < 10){
    // when Forward distance is <10cm, turn left
    motors.rightMotor(100); 
    motors.leftMotor(100);
    delay(800);  
    while(R_distance>15){
      R_distance = R_sr04.Distance();
      delay(100);
    }
            
  }
  else{
    error = R_distance-R_desire;
    float L_val = -110-P*error;
    float R_val = 110-P*error;
    if (L_val<-180){
      L_val = -180;
    }
    if (R_val>180){
      R_val = 180;
    }
    motors.leftMotor(L_val); 
    motors.rightMotor(R_val); 
    delay(100); 
  }

}


/*
// drive forward -- instead of using motors.drive(); Here is another way.
  motors.rightMotor(150); // Turn on right motor clockwise medium power (motorPower = 150) 
  motors.leftMotor(-150); // Turn on left motor counter clockwise medium power (motorPower = 150) 
  delay(1000);       // for 1000 ms.
  motors.brake();    // brake() motors

  // pivot -- spinning both motors CCW causes the RedBot to turn to the right
  motors.rightMotor(-100); // Turn CCW at motorPower of 100
  motors.leftMotor(-100);  // Turn CCW at motorPower of 100
  delay(500);        // for 500 ms.    
  motors.brake();    // brake() motors
  delay(500);        // for 500 ms.    

  // drive forward -- instead of using motors.drive(); Here is another way.
  motors.rightMotor(150); // Turn on right motor clockwise medium power (motorPower = 150) 
  motors.leftMotor(-150); // Turn on left motor counter clockwise medium power (motorPower = 150)
  delay(1000);       // for 1000 ms.
  motors.brake();     // brake() motors
*/
