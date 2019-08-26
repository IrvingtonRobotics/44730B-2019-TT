
#include "main.h"
#include "okapi/api.hpp"
#include "robot.h"

using namespace okapi;


void init(){
  ChassisControllerIntegrated claw = ChassisControllerFactory::create(LEFTCLAW_MOTOR,
    RIGHTCLAW_MOTOR, AbstractMotor::gearset::green);
     ControllerButton presetButtons[2] = {
       ControllerButton(ControllerDigital::up),
       ControllerButton(ControllerDigital::down)
     };
};
