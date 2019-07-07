#ifndef CLAW_H
#define CLAW_H

#include "main.h"
#include "okapi/api.hpp"

const int LEFTCLAW_MOTOR = 0;
const int RIGHTCLAW_MOTOR = 0;

class Claw {
public:
  ChassisControllerIntegrated claw = AsyncControllerFactory::create(LEFTCLAW_MOTOR,
     RIGHTCLAW_MOTOR, AbstractMotor::gearset::green);
};


#endif
