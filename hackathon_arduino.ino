#include <AFMotor.h>

AF_DCMotor left_motor(1);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  left_motor.run(RELEASE);
}
