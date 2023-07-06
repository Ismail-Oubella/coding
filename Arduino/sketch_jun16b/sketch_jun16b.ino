#include <Arduino.h>

const int ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.print("Sensor Value: ");
  digitalWrite(ledPin, HIGH);
  delay(1000);  // LED on for 1 second
  digitalWrite(ledPin, LOW);
  delay(1000);  // LED off for 1 second
} 
