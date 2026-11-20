#include <Arduino.h>
#include <Servo.h>  

Servo myServo;

const int trigPin = 9;
const int echoPin =  10;
const int servoMotorPin = 2;

const int rampUp = 90;
const int rampDown = 0;

float scanDuration, scanedDistance;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoMotorPin);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  scanDuration = pulseIn(echoPin, HIGH);
  scanedDistance = (scanDuration*0.343)/2;

  Serial.print("Distance: ");
  Serial.println(scanedDistance);
  delay(100);

  if (scanedDistance > 0 && scanedDistance <= 50) {
    myServo.write(rampUp);
  }
  else {
    myServo.write(rampDown);
  }
  delay(15);
}
