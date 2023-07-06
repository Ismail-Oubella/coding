// Include the Arduino IDE's built-in LED library
#include <Arduino.h>
// Define the pin for the LED
const int ledPin = 3;
// The setup function runs once when the Arduino is powered on or reset
void setup() {
  // Set the pin for the LED as an output
  pinMode(ledPin, OUTPUT);
}
// The loop function runs repeatedly forever
void loop() {
  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  // Wait for one second
  delay(1000);
  // Turn off the LED
  digitalWrite(ledPin, LOW);
  // Wait for one second
  delay(1000);
}
