#include <AFMotor.h>

AF_DCMotor leftMotor(1);

/*
motor.run(FORWARD/BACKWARD/RELEASE)
motor.setSpeed(0-255) corresponds to 0-5V
*/


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  leftMotor.run(RELEASE);
}

void forward() {

}

void backward() {

}

void turnRight() {

}

void turnLeft() {
  
}