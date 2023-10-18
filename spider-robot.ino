#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PCA9685_ADDRESS 0x40

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDRESS);

#define MIN_PULSE_WIDTH 150
#define MAX_PULSE_WIDTH 600
#define FREQUENCY 60

const int frontTibiaL = 5;
const int frontTibiaR = 2;
const int backTibiaL = 6;
const int backTibiaR = 7;

const int frontFemurL = 0;
const int frontFemurR = 3;
const int backFemurL = 1;
const int backFemurR = 4;

void moveServo(uint8_t servo, int angle) {
  if(angle < 0) {
    angle = 0;
  } else if (angle > 180) {
    angle = 180;
  }

  uint16_t pulse_width = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);

  pwm.setPWM(servo, 0, pulse_width);
}

void standUp() {
  moveServo(frontTibiaL, 0);
  moveServo(frontTibiaR, 0);
  moveServo(backTibiaL, 0);
  moveServo(backTibiaR, 0);
}

void sitDown() {
  moveServo(frontTibiaL, 90);
  moveServo(frontTibiaR, 90);
  moveServo(backTibiaL, 90);
  moveServo(backTibiaR, 90);
}

void setup() {
  Wire.begin();

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(FREQUENCY);
  standUp();
}

void loop() {
}
