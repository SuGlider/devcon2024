#include <Arduino.h>

void setup() {
  Serial.begin(115200); // Using UART0
}

void loop() {
  Serial.println("Hello world!");
  delay(1000);
}
