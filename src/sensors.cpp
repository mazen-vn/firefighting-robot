#include "sensors.h"
#include <Arduino.h>

void initializeSensors() {
  pinMode(FLAME_LEFT, INPUT);
  pinMode(FLAME_RIGHT, INPUT);
  pinMode(FLAME_FORWARD, INPUT);
}

bool flameDetectedLeft() {
  return digitalRead(FLAME_LEFT) == LOW;
}

bool flameDetectedRight() {
  return digitalRead(FLAME_RIGHT) == LOW;
}

bool flameDetectedForward() {
  return digitalRead(FLAME_FORWARD) == LOW;
}

bool anyFlameDetected() {
  return flameDetectedLeft() || flameDetectedRight() || flameDetectedForward();
}
