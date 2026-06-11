#include <AccelStepper.h>

// Define stepper pins
#define STEP1_PIN 8      // Step pin
#define DIR1_PIN 9       // Direction pin
#define STEP2_PIN 10
#define DIR2_PIN 11
#define STEP3_PIN 12
#define DIR3_PIN 13

// Microstepping control pins
#define M0_PIN 7
#define M1_PIN 6
#define M2_PIN 5

// On/off timers in seconds
#define MOTOR1_ON 14
#define MOTOR1_OFF 3
#define MOTOR2_ON 8
#define MOTOR2_OFF 2
#define MOTOR3_ON 10
#define MOTOR3_OFF 1

// Steps per revolution for the motor
const float stepsPerRevolution = 200;
// Microstepping multiplier (1, 2, 4, 8, 16, or 32)
int microstepSetting = 32;

// AccelStepper instance in driver mode
AccelStepper stepper1(AccelStepper::DRIVER, STEP1_PIN, DIR1_PIN);
AccelStepper stepper2(AccelStepper::DRIVER, STEP2_PIN, DIR2_PIN);
AccelStepper stepper3(AccelStepper::DRIVER, STEP3_PIN, DIR3_PIN);

void setup() {
  // Set microstepping pins as outputs
  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);

  // Set microstepping mode (adjust as needed: HIGH or LOW)
  digitalWrite(M0_PIN, HIGH);  // Set to LOW or HIGH for desired microstep setting
  digitalWrite(M1_PIN, HIGH);  // Set to LOW or HIGH for desired microstep setting
  digitalWrite(M2_PIN, HIGH);  // Set to LOW or HIGH for desired microstep setting

  // Set the desired RPM and the max RPM
  float desiredRPM = 6; // Set the desired speed in rpm (revolutions per minute)
  float MaxRPM = 60; // Set max speed in rpm (revolutions per minute)

  // Calculate and set the desired and max speed in steps per second
  float speedStepsPerSec = (microstepSetting * stepsPerRevolution*desiredRPM) / 60.0;
  float Max_Speed_StepsPerSec = microstepSetting * stepsPerRevolution * MaxRPM / 60; // Specify max speed in steps/sec (converted from RPM)
  stepper1.setMaxSpeed(Max_Speed_StepsPerSec);
  stepper1.setSpeed(speedStepsPerSec);
  stepper2.setMaxSpeed(Max_Speed_StepsPerSec);
  stepper2.setSpeed(speedStepsPerSec);
  stepper3.setMaxSpeed(Max_Speed_StepsPerSec);
  stepper3.setSpeed(speedStepsPerSec);
}

void loop() {

  // Motor1 on/off
  secondsInInterval = millis() % (MOTOR1_ON + MOTOR1_OFF)
  if secondsInInterval < MOTOR1_ON {
    // Run the motor at constant speed
    stepper1.runSpeed();
  }

  // Motor2 on/off
  secondsInInterval = millis() % (MOTOR2_ON + MOTOR2_OFF)
  if secondsInInterval < MOTOR2_ON {
    // Run the motor at constant speed
    stepper2.runSpeed();
  }

  // Motor3 on/off
  secondsInInterval = millis() % (MOTOR3_ON + MOTOR3_OFF)
  if secondsInInterval < MOTOR3_ON {
    // Run the motor at constant speed
    stepper3.runSpeed();
  }

}