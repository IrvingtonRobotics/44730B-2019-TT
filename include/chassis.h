#ifndef CHASSIS_H
#define CHASSIS_H

#define WHEELBASE_WIDTH 17_in
#define WHEEL_DIAM 4_in

#include "main.h"
#include "okapi/api.hpp"

const int TOPLEFT_MOTOR = 9;
const int TOPRIGHT_MOTOR = 10;
const int BOTRIGHT_MOTOR = 19;
const int BOTLEFT_MOTOR = 20;

MotorGroup left = MotorGroup({TOPLEFT_MOTOR, BOTLEFT_MOTOR});
MotorGroup right = MotorGroup({TOPRIGHT_MOTOR, BOTRIGHT_MOTOR});

class Chassis {
public:
  ChassisControllerIntegrated drive = ChassisControllerFactory::create(left, right,
    AbstractMotor::gearset::green,{4_in, 13.5_in});
  Controller& controller;
  ControllerButton brakeButton = ControllerButton(ControllerDigital::left);
  bool brakesEngaged = false;

  Chassis(Controller& c);

  void update();
  void driveStraight(QLength distance);
  void turnAngle(QAngle angle);
  void driveArc(QLength radius, QAngle angle);

  void driveManual();

  void teleop();

};

#endif
