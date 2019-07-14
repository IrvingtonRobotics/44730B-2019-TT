#ifndef LIFT_H
#define LIFT_H

#include "main.h"
#include "okapi/api.hpp"

extern Motor leftLiftmotor;
extern Motor rightLiftmotor;

class Arm {
public:
  ChassisControllerIntegrated lift = ChassisControllerFactory::create(leftLiftmotor,
     rightLiftmotor, AbstractMotor::gearset::green);
  ControllerButton presetButtons[3] = {
      ControllerButton(ControllerDigital::down),
      ControllerButton(ControllerDigital::right),
      ControllerButton(ControllerDigital::up)
  };
  int targetPreset = 0;
   int targetTicks = 300;

   int timeStart = pros::c::millis();

   double totalError = 0;
   double lastError = 0;

  Arm();
    void teleop();
    void moveTo(int preset);
    static void runPID(void* self);
    void avoidPuncherPath();
    void returnToInitial();
    bool isSafeToShoot();
    void waitUnilSafeToShoot();
    bool isSettled();
    void waitUntilSettled();

};
#endif
