#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial HC06(10, 11);
AF_DCMotor leftMotor(3);
AF_DCMotor rightMotor(4);
Servo turnServo;
int midPos = 103;

void setup() {
  HC06.begin(9600);
  turnServo.attach(9);
  turnServo.write(midPos);
}

void loop() {
  if (HC06.available() > 0) {
    char receive = HC06.read();
    if (receive == 'w') {
      forward();
    }
    if (receive == 'a') {
      turnLeftBackward();
    }
    if (receive == 's') {
      backward();
    }
    if (receive == 'd') {
      turnRightBackward();
    }
    if (receive == 'q') {
      turnLeftForward();
    }
    if (receive == 'e') {
      turnRightForward();
    }
    if (receive == 'z') {
      kill();
    }
  }
}

void kill() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
  turnServo.write(midPos);
}

void backward() {
  turnServo.write(midPos);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(FORWARD);
  leftMotor.run(FORWARD);
}

void forward() {
  turnServo.write(midPos);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(BACKWARD);
  leftMotor.run(BACKWARD);
}

void turnRightForward() {
  turnServo.write(midPos-45);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(BACKWARD);
  leftMotor.run(BACKWARD);
}
 void turnRightBackward() {
  turnServo.write(midPos-45);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(FORWARD);
  leftMotor.run(FORWARD);
 }

void turnLeftForward() {
  turnServo.write(midPos+45);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(BACKWARD);
  leftMotor.run(BACKWARD);
}

void turnLeftBackward() {
  turnServo.write(midPos+45);
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  rightMotor.run(FORWARD);
  leftMotor.run(FORWARD);
}
