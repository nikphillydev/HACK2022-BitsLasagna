#include <AFMotor.h>

AF_DCMotor leftMotor(1);
AF_DCMotor rightMotor(2);

/*
motor.run(FORWARD/BACKWARD/RELEASE)
motor.setSpeed(0-255) corresponds to 0-5V
*/


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(3000);
}

void forward() {
leftMotor.setSpeed(255);
rightMotor.setSpeed(255);
rightMotor.run(FORWARD);
leftMotor.run(BACKWARD);
delay(3000);
leftMotor.run(RELEASE);
rightMotor.run(RELEASE);
}

void backward() {
leftMotor.setSpeed(255);
rightMotor.setSpeed(255);
rightMotor.run(BACKWARD);
leftMotor.run(FORWARD);
delay(3000);
leftMotor.run(RELEASE);
rightMotor.run(RELEASE);
}

void turnRight() {
leftMotor.setSpeed(255);
leftMotor.run(BACKWARD);
delay(3000);
leftMotor.run(RELEASE);
}

void turnLeft() {
rightMotor.setSpeed(255);
rightMotor.run(FORWARD);
delay(3000);
rightMotor.run(RELEASE);
}