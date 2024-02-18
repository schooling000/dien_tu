#include <Arduino.h>
#include <Led.h>

Led led(13);

void setup() {
   Serial.begin(9600);
}

void loop() {
    led.on();
    delay(200);
    led.off();
}
