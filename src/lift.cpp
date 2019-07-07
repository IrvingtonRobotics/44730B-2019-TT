#include "lift.h"
#include "main.h"

const double ArmPresets[4] = {350, 1000, 3440, 1000};

Arm::Arm() {
  lift.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
  lift.setBrakeMode(AbstractMotor::brakeMode::hold);
}

const double kP = 0.05;
const double kI = 0.00001;
const double kD = 0.01;

void Arm::moveTo(int position) {
  targetPreset = position;
  targetTicks = ArmPresets[position];
  totalError = 0;
  timeStart = pros::c::millis();
}

//Cant getPosition with lift ChassisControllerFactory

// void Arm::runPID() {
//   for (;;) {
//
//     pros::lcd::print(1, "TwoBar: CurrentAngl: %04d TargetAngl: %04d", (int)lift.getPosition(), self->targetTicks);
//
//     double reading = lift.getPosition();
//     double error = reading - self->targetTicks;
//     self->totalError += error;
//
//     double speed = error * kP;
//     speed += self->totalError * kI;
//     speed += (error - self->lastError) * kD;
//     //pros::lcd::print(1, "TwoBar Speed: %03d Error: %03d", (int)speed, (int)error);
//
//     self->lift.moveVelocity(-speed);
//
//     self->lastError = error;
//
//
//     pros::Task::delay(5);
//   }
// }
void Arm::waitUntilSettled() {
  while (!isSettled()) {
    pros::Task::delay(10);
  }
}

void Arm::teleop() {
  for (int i = 0; i < 3; ++i) {
    if (presetButtons[i].changedToPressed()) {
      moveTo(i);
    }
  }
}

void Arm::returnToInitial() {
  if (targetPreset == 3) {
    moveTo(0);
  }
}
