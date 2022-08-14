//Setting up interrupt pins
#define EncoderInterruptA 0
#define EncoderInterruptB 1
#define EncoderPinA 2 //Must be pin 2 (Only pin 2 and 3 are interrupt pins)
#define EncoderPinB 3 //Must be pin 3

const byte motorPin = 10; // Define pin 10
volatile byte state = LOW; //the initial state
float RPM = 0 ; // RPM
float dcount = 0; // count


unsigned long t1=0;
unsigned long t0=0;
unsigned long dt=0;
unsigned long st=500;

//Defines variables for pin states
volatile bool EncoderASet;
volatile bool EncoderBSet;
volatile bool EncoderAPrev;
volatile bool EncoderBPrev;

volatile long EncoderTicks = 0; //Initializing Tick COunter
volatile long PrevEncoderTicks = 0; 
float MotorCPR = 542; //CHANGE TO CORRECT CPR

void setup()
{
  pinMode(motorPin, OUTPUT);  // sets the pin as output
  pinMode(EncoderPinA, INPUT);      // sets pin A as input
  digitalWrite(EncoderPinA, LOW);  // turn on pullup resistors
  pinMode(EncoderPinB, INPUT);      // sets pin B as input
  digitalWrite(EncoderPinB, LOW);  // turn on pullup resistors
  
  attachInterrupt(digitalPinToInterrupt(EncoderPinA), HandleMotorInterruptA, CHANGE); //Setting up first interrupt
  attachInterrupt(digitalPinToInterrupt(EncoderPinB), HandleMotorInterruptB, CHANGE); //Setting up second interrupt
  Serial.begin(115200);
  Serial.println("Time[ms], Counts , RPM");
  Serial.println(" ");
  analogWrite(motorPin,255*0);//Initial PWM volts
  delay(5000);
}

void loop()
{
       
    t1 = millis();   // Reset the delta_time
    dt = t1-t0;
    if (dt >= st) {           // While dt is smaller than the sample time ...
      dcount = abs(EncoderTicks - PrevEncoderTicks);
      RPM = (dcount*60*1000)/(542*dt);
      print_count();
      PrevEncoderTicks = EncoderTicks;
      
      t0 = millis();   // ... stay in this loop checking the clock.
    }

    analogWrite(motorPin,255*1); // Sends PWM signal to our motor controller

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

void print_count(){
    Serial.print(t1);                      // Print data to serial monitor
    Serial.print(",  ");
    Serial.print(EncoderTicks);
    Serial.print(",  ");
    Serial.println(RPM);
}
