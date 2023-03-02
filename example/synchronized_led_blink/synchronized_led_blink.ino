#include <PinChangeInterrupt.h>

#define ATTACH_PIN 10
#define LED_PIN    13

void pin_change_cb();

PinChangeInterrupt pcint;

void setup() {
  pcint.attachInterrupt(ATTACH_PIN, pin_change_cb);
}

void loop() {
  
}

void pin_change_cb() {
  volatile static bool led_flg = true;

  // RISING MODE
  if(digitalRead(ATTACH_PIN)) {
    digitalWrite(LED_PIN, led_flg);
    led_flg = !led_flg;
  }
}

