#include <Arduino.h>
void controlLED();

// Pin assignments
const int buttonPin = 2;
const int ledPin = 8;

void setup()
{
  // Initialize pins and set up initial conditions
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  // Main code to run repeatedly
  if (digitalRead(buttonPin) == HIGH)
    digitalWrite(ledPin, HIGH); // Turn on the LED
  else
    digitalWrite(ledPin, LOW); // Turn off the LED
}
