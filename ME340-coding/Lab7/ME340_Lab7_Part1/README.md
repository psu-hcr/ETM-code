If you are don't know Arduino code very well, let's break the code down:
```
// Define pin 
int phototransD = 9; //the digital input pin
int phototransA = A0;//the analog input pin
```
Line 2 & 3 declare two valuables to store the pin number. 
```
// decrlaring variables to store the input values
int val =0;
int aval =0;
```
Line 4 & 5 declare two valuables to store the input reading from two pin. Here, we assign 0 to both of valuables to initialize them. 
```
void setup () {
```
Line 7 is the beginning of the **setup( )** function. The function ends at line 15. The purpose of the **setup** function is to initialize variables, pin modes, start using libraries. The setup function will only run once, after each powerup or reset of the Arduino board. All Arduino code must have the **setup** function.
```
pinMode(phototransD , INPUT);
pinMode(phototransA , INPUT);
```
Line 9 & 10 define the pin mode. **phototransD** is the name of the pin and **INPUT** indicates that this pin is used as input. Some of pins on Arduino can be used as input or output. The purpose of pins must be defined in the **setup** function.
```
Serial.begin (9600);
```
Line 12 initializes the serial communication. **9600** is the data rate in bits per second for serial data transmission, called baud. 
```
pinMode(LED_BUILTIN , OUTPUT);
```
Line 14 also defines the pin mode. Arduino Uno has an on-board LED. The constant **LED_BUILTIN** is the number of the pin to which the on-board LED is connected.
```
void loop() {
```
Line 18 is the beginning of the **loop( )** function. The function ends at line 26.The **loop( )** function runs over and over again forever. 
```
val=digitalRead(phototransD);
```
Line 20 reads the value from **phototransD"** pin. The return value is either HIGH (1) or LOW (0).
```
aval = analogRead(phototransA);
```
Line 21 reads the value from **phototransA** pin. The return value is an int between 0 and 1023. This is because Arduino Uno has a 10-bit analog to digital converter. It maps input voltages between 0 and 5 volts into integer values between 0 and 1023. 
```
digitalWrite(LED_BUILTIN , val);
```
Line 22 controls the on-board LED. When **val** is 0, LED is off. When **val** is 1, LED is on.
```
Serial.println(aval);
```
Line 24 prints value in **aval** to the serial port as human-readable ASCII text. We can use *Serial Monitor* in Arduino IDE to read data from Arduino on PC. *Serial Monitor* is under the *tools* tab in Arduino IDE.
```
delay (1000);
```
Line 25 pauses the program for the amount of time (in milliseconds). Main purpose for pause is to make sure serial port has enough time for communication. 
