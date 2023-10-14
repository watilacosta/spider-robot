#include <Servo.h>

Servo frontLFemur; // 0
Servo frontLTibia; // 5
Servo frontRFemur; // 3
Servo frontRTibia; // 2

Servo backLFemur; // 1
Servo backLTibia; // 6
Servo backRFemur; // 4
Servo backRTibia; // 7


void setup() {
  frontLFemur.attach(0);
  frontLTibia.attach(5);
  frontRFemur.attach(3);
  frontRTibia.attach(2);

  backLFemur.attach(1);
  backLTibia.attach(6);
  backRFemur.attach(4);
  backRTibia.attach(7);
}

void loop() {
  frontLFemur.write(90);
  frontLTibia.write(90);
  frontRFemur.write(90);
  frontRTibia.write(90);
}
