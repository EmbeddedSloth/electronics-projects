#include <Arduino.h>
#include <Servo.h>  

Servo myServo;

const int trigPin = 10;
const int echoPin =  9;

const int servoMotorPin = 6;

const int redLEDPin = 8;
const int greenLEDPin = 7;

const int piezoPin = 4;

const int switchPin = 3;

const int rampUp = 90;
const int rampDown = 0;

float scanDuration, scanedDistance;
bool isRampUp = false;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoMotorPin);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(switchPin, INPUT);
  
  myServo.write(rampDown);
  digitalWrite(redLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);

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
  Serial.println(digitalRead(switchPin));
  
  if (scanedDistance > 0 && scanedDistance <= 50) {
    if (isRampUp == false) {
      myServo.write(rampUp);
      tone(piezoPin,1000,200);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      isRampUp = true;
    }
 }
  else if (scanedDistance > 70) { 
    if (isRampUp == true) {
      delay(3000);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(greenLEDPin, LOW);
      delay(1500);
      myServo.write(rampDown);
      isRampUp = false;
      delay(5000);
    }
  }
  if (digitalRead(switchPin) == HIGH) {
    if (isRampUp == false) {
      myServo.write(rampUp);
      tone(piezoPin,1000,200);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      isRampUp = true;
    }
  }
}