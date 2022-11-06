#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial HC06(10, 11);
AF_DCMotor leftMotor(1);
AF_DCMotor rightMotor(2);

/*
motor.run(FORWARD/BACKWARD/RELEASE)
motor.setSpeed(0-255) corresponds to 0-5V
*/


void setup() {
  // put your setup code here, to run once:
  HC06.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (HC06.available() > 0) {
    char receive = HC06.read();
    if (receive == 'w') {
      forward();
    }
    if (receive == 'a') {
      turnLeft();
    }
    if (receive == 's') {
      backward();
    }
    if (receive == 'd') {
      turnRight();
    }
    if (receive == 'q') {
      kill();
    }
  }
}

void kill() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}

void forward() {
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(FORWARD);
  leftMotor.run(BACKWARD);
  // delay(100);
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
}

void backward() {
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(BACKWARD);
  leftMotor.run(FORWARD);
  // delay(100);
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
}

void turnRight() {
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
  leftMotor.setSpeed(255);
  leftMotor.run(BACKWARD);
  // delay(100);
  // leftMotor.run(RELEASE);
}

void turnLeft() {
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
  rightMotor.setSpeed(255);
  rightMotor.run(FORWARD);
  // delay(100);
  // rightMotor.run(RELEASE);
}
