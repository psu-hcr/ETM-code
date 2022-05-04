//https://www.hackster.io/Marcazzan_M/motor-speed-control-with-one-transistor-0921a8
const byte CHA = 2; // Define pin 2
const byte CHB = 3; // Define pin 3
const byte motorPin = 10; // Define pin 10
volatile byte state = LOW; //the initial state
volatile long count = 0 ; // count
volatile long count_last = 0; // count
float RPM = 0 ; // RPM
float dcount = 0; // count


unsigned long t1=0;
unsigned long t0=0;
unsigned long dt=0;
unsigned long st=10;

void setup()
{
  pinMode(motorPin, OUTPUT);  // sets the pin as output
  pinMode(CHA, INPUT_PULLUP); // Set the CHA as INPUT_PULLUP
  pinMode(CHB, INPUT_PULLUP); // Set the CHB as INPUT_PULLUP
  
  attachInterrupt(digitalPinToInterrupt(CHA), flag, RISING); // External interrupt: the  function will be called when the signal on CHA pin changes
  //attachInterrupt(digitalPinToInterrupt(CHB), flag, RISING); // External interrupt: the  function will be called when the signal on CHB pin changes
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
      dcount = count - count_last;
      RPM = (dcount*60*1000)/(542*dt);
      print_count();
      count_last = count;
      
      t0 = millis();   // ... stay in this loop checking the clock.
    }

    analogWrite(motorPin,255*1); // Sends PWM signal to our motor controller

}

//interrupt
void flag() {
  state = 1;
  
  //add 1 to count for CW
  if (digitalRead(CHA) && digitalRead(CHB)) {
    count++;
  }

  //substract 1 from count for CCW
  if (digitalRead(CHA) && !digitalRead(CHB)) {
    count--;
  }
}

void print_count(){
    if (state)
  {
    Serial.print(t1);                      // Print data to serial monitor
    Serial.print(",  ");
    Serial.print(count);
    Serial.print(",  ");
    Serial.print(count_last);
    Serial.print(",  ");
    Serial.println(RPM);
    state = 0;//clear state
  }//end if
}
