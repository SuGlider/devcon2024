#include <Arduino.h>

void setup() {
  Serial.begin(); // USB CDC doens't need a baud rate
  while(!Serial) delay(100);  // waits for the Serial Monitor to be open

  delay(500);
  Serial.println("\r\nStarting with USB OTG CDC.\r\n");
}

void loop() {
  Serial.println("Hello world!");
  delay(1000);
}
