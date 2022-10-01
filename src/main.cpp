// Mohawk College - COMP-10184 
// 
// Digital Input/Output Lab - Test Program 
//
// I, Julia Norrish, 000839030 certify that this material is my original work.  No other person's work has been used without due acknowledgement.
// 
#include <Arduino.h> 

int iVal; 
int state;
int oldState;
bool LEDOn = true;
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023); 
} 
 
 
void loop() {
  // read the button
  state = digitalRead(D5);

  // check if the button has been pressed 
  if (state != oldState) {
    // save the old state
    oldState = state;

    if (state == 1){
      // toggle the state of the LED
      LEDOn = !LEDOn;
    }
  }

  // if the LED is on, control it using the variable resistor
  if (LEDOn){
    iVal = analogRead(A0);
    // set the PWM pulse width
    analogWrite(D4, iVal);
    delay(1);
  }
  else {
    // turn the LED off
    digitalWrite(D4, 1);
  }
} 
