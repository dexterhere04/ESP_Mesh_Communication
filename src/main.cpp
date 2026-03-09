#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(2000);  // give time for serial monitor
    Serial.println("ESP32 started");
}

void loop() {
    Serial.println("running...");
    delay(1000);
}