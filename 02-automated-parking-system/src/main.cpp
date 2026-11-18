#include <Arduino.h>
#include <Servo.h>  

Servo myServo;

const int pushButtonPin = 2;
const int servoMotorPin = 9;

const int rampUp = 90;
const int rampDown = 0;

void setup() {
  pinMode(pushButtonPin, INPUT);
  myServo.attach(servoMotorPin);
}

void loop() {
  if (digitalRead(pushButtonPin) == HIGH) {
    myServo.write(rampUp);
  }
  else {
    myServo.write(rampDown);
  }
  delay(15);
}
