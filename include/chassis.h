#ifndef CHASSIS_H
#define CHASSIS_H

#include "main.h"
#include "okapi/api.hpp"

extern MotorGroup leftMotors;
extern MotorGroup rightMotors;

class Chassis {
public:
  ChassisControllerIntegrated drive = ChassisControllerFactory::create(leftMotors, rightMotors,
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
