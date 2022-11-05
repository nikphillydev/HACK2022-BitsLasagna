#include <AFMotor.h>

AF_DCMotor leftMotor(1);
AF_DCMotor rightMotor();

/*
motor.run(FORWARD/BACKWARD/RELEASE)
motor.setSpeed(0-255) corresponds to 0-5V
*/


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  backward();
  left();
  right();
}

void forward() {
leftMotor.setSpeed(255);
rightMotor.setSpeed(255);
rightMotor.run(FORWARD);
leftMotor.run(FORWARD);
delay(3000);
leftMotor.run(RELEASE);
rightMotor.run(RELEASE);
}

void backward() {
leftMotor.setSpeed(255);
rightMotor.setSpeed(255);
rightMotor.run(BACKWARD);
leftMotor.run(BACKWARD);
delay(3000);
leftMotor.run(RELEASE);
rightMotor.run(RELEASE);
}

void turnRight() {
leftMotor.setSpeed(255);
rightMotor.setSpeed(100);
rightMotor.run(FORWARD);
leftMotor.run(FORWARD);
delay(3000);
leftMotor.run(RELEASE);
rightMotor.run(RELEASE);
}

void turnLeft() {
leftMotor.setSpeed(100);
rightMotor.setSpeed(255);
rightMotor.run(FORWARD);
leftMotor.run(FORWARD);
delay(3000);
leftMotor.run(RELEASE);
rightMotor.run(RELEASE);
}