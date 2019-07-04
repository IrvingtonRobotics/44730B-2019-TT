#include "main.h"
#include "okapi/api.hpp"

using namespace okapi;
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 const int TOPLEFT_MOTOR = 9;
 const int TOPRIGHT_MOTOR = -10;
 const int BOTRIGHT_MOTOR = -19;
 const int BOTLEFT_MOTOR = 20;
 auto drive_auton = ChassisControllerFactory::create(TOPLEFT_MOTOR, TOPRIGHT_MOTOR,  BOTRIGHT_MOTOR, BOTLEFT_MOTOR,   AbstractMotor::gearset::green,
  {4_in, 13.5_in});

void autonomous(){


  drive_auton.turnAngle(180_deg);
  drive_auton.moveDistance(5_ft);


}