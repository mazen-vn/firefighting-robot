#include "control_logic.h"
#include <Arduino.h>

// Pin Definitions
const int pump = A0;
const int LM1 = 12, LM2 = 4, RM1 = 7, RM2 = 2;
const int Left = 10, Right = 9, Forward = 8;
int pos;
bool fire = false;

void initializePins() {
  pinMode(pump, OUTPUT);
  pinMode(LM1, OUTPUT); pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT); pinMode(RM2, OUTPUT);
  pinMode(Left, INPUT); pinMode(Right, INPUT); pinMode(Forward, INPUT);
  analogWrite(3, 150);  // Motor Speed
  analogWrite(5, 150);
}

void initializeServo(Servo &servo) {
  servo.attach(11);
  servo.write(90);
}

bool isFireDetected() {
  return digitalRead(Forward) == LOW || digitalRead(Left) == LOW || digitalRead(Right) == LOW;
}

void handleFire(Servo &servo) {
  digitalWrite(LM1, HIGH); digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH); digitalWrite(RM2, HIGH);
  digitalWrite(pump, HIGH);
  delay(500);

  for (pos = 50; pos <= 130; pos++) {
    servo.write(pos);
    delay(10);
  }
  for (pos = 130; pos >= 50; pos--) {
    servo.write(pos);
    delay(10);
  }

  digitalWrite(pump, LOW);
  servo.write(90);
}

void moveBasedOnSensors() {
  if (digitalRead(Left) && digitalRead(Right) && digitalRead(Forward)) {
    digitalWrite(LM1, HIGH); digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH); digitalWrite(RM2, HIGH);
  } else if (digitalRead(Forward) == LOW) {
    digitalWrite(LM1, HIGH); digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH); digitalWrite(RM2, LOW);
  } else if (digitalRead(Left) == LOW) {
    digitalWrite(LM1, HIGH); digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH); digitalWrite(RM2, HIGH);
  } else if (digitalRead(Right) == LOW) {
    digitalWrite(LM1, HIGH); digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH); digitalWrite(RM2, LOW);
  }

  delay(300);
}
