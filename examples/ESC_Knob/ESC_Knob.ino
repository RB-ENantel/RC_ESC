/*
  ESC_Knob
  Controlling an R/C ESC (Electronic Speed Controller) speed using a potentiometer (variable resistor)
  This is using a modified version of the "Knob" example in the "Servo" library.
    
  27 April 2017
  by Eric Nantel
  
  Servo & Knob links
  http://www.arduino.cc/en/Tutorial/Knob
  http://people.interaction-ivrea.it/m.rinott
 */
#include "ESC.h"
#define LED_PIN (13)                    // Pin for the LED 
#define POT_PIN (A0)                    // Analog pin used to connect the potentiometer

ESC myESC (9, 1000, 2000, 500);         // ESC_Name (PIN, Minimum Value, Maximum Value, Arm Value)

int val;                                // variable to read the value from the analog pin

void setup() {
  pinMode(LED_PIN, OUTPUT);             // LED Visual Output
  myESC.arm();                          // Send the Arm value
  digitalWrite(LED_PIN, HIGH);          // LED High Once Armed
  delay(5000);                          // Wait for a while
}

void loop() {
  val = analogRead(POT_PIN);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);  // scale it to use it with the ESC (value between 1000 and 2000)
  myESC.speed(val);                     // sets the ESC speed according to the scaled value
  delay(15);                            // Wait for a while
}

