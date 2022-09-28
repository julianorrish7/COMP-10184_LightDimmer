// Mohawk College - COMP-10184 
// 
// Digital Input/Output Lab - Test Program 
//
// I, Julia Norrish, 000839030 certify that this material is my original work.  No other person's work has been used without due acknowledgement.
// 
#include <Arduino.h> 

int iButton; 
int iVal; 
int state;
int oldState;
 
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
  state = digitalRead(D5);

  if (state != oldState){
    // read digitized value from the D1 Mini's A/D convertor 
    iVal = analogRead(A0); 
    
    // set the PWM pulse width 
    analogWrite(D4, iVal); 

    // wait 1ms to add DRAMA! 
    delay(1); 
  }

  else {
    // iButton = digitalRead(D5); 
    digitalWrite(D4, 1); 
  }
  
  oldState = state;
} 