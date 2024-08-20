#include <Arduino.h>

void setup() {
  Serial.begin(115200); // This shall use UART0 or if configured, the USB CDC port
  Serial.setDebugOutput(true); // Necessary for the HW Serial CDC port
  while(!Serial) delay(100); // waits for the Serial Terminal to be open - only works for the USB CDC port

  Serial.println("Don't forget to select the Arduino Log Level using MenuConfig...");
}

void loop() {
  Serial.println("Hello world!");

  // following message will be displayed based on the Arduino Log Level selected by Menuconfig
  // For that run idf.py menuconfig and got to Arduino option
  log_e("This is an Error Level Log message!");
  log_w("This is a Warning Level Log message!");
  log_i("This is an Info Level Log message!");
  log_d("This is a Debug Level Log message!");
  log_v("This is a Verbose Level Log message!");

  delay(1000);
}
