#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MIN_PULSE_WIDTH 150
#define MAX_PULSE_WIDTH 600
#define DEFAULT_PULSE_WIDTH 150
#define FREQUENCY 60

const int tibiaFrontalE = 5;
const int tibiaFrontalD = 2;
const int tibiaTraseiraE = 6;
const int tibiaTraseiraD = 7;

const int femurFrontalE = 0;
const int femurFrontalD = 3;
const int femurTraseiroE = 1;
const int femurTraseiroD = 4;

const int tibiasCount = 4;
const int femursCount = 4;

int pulseWidth(int angle) {
  int pulse_wide, analog_value;

  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float (pulse_wide) / 1000000 * FREQUENCY * 4096);

  return analog_value;
}

void setup() {
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  delay(1000);

  pwm.setPWM(tibiaFrontalE, 0, pulseWidth(90));
  pwm.setPWM(tibiaFrontalD, 0, pulseWidth(90));
  pwm.setPWM(tibiaTraseiraE, 0, pulseWidth(90));
  pwm.setPWM(tibiaTraseiraD, 0, pulseWidth(90));
}

void loop() {
  delay(1000);
  pwm.setPWM(tibiaFrontalE, 0, pulseWidth(180));
  pwm.setPWM(tibiaFrontalD, 0, pulseWidth(180));
  pwm.setPWM(tibiaTraseiraE, 0, pulseWidth(180));
  pwm.setPWM(tibiaTraseiraD, 0, pulseWidth(180));
  delay(1000);
  pwm.setPWM(tibiaFrontalE, 0, pulseWidth(90));
  pwm.setPWM(tibiaFrontalD, 0, pulseWidth(90));
  pwm.setPWM(tibiaTraseiraE, 0, pulseWidth(90));
  pwm.setPWM(tibiaTraseiraD, 0, pulseWidth(90));
}
