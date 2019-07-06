#ifndef CHASSIS_H
#define CHASSIS_H

#include "main.h"
#include "okapi/api.hpp"

const int TOPLEFT_MOTOR = 9;
const int TOPRIGHT_MOTOR = 10;
const int BOTRIGHT_MOTOR = 19;
const int BOTLEFT_MOTOR = 20;

class Chassis {
public:
  ChassisControllerIntegrated drive = ChassisControllerFactory::create(TOPLEFT_MOTOR,
    TOPRIGHT_MOTOR, BOTRIGHT_MOTOR, BOTLEFT_MOTOR, okapi::AbstractMotor::gearset::green,
    {4_in, 13.5_in});
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
