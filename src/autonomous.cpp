#include "main.h"
#include "okapi/api.hpp"
#include "chassis.h"
#include "lift.h"
#include "autonomousSelector.h"
#include "robot.h"

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

extern Chassis chassis1;
extern autonomousSelector autoSelector;
// extern Arm arm;

Motor leftLiftmotor = LEFTLIFT_MOTOR;
Motor rightLiftmotor = RIGHTLIFT_MOTOR;

MotorGroup leftMotors = MotorGroup({TOPLEFT_MOTOR, BOTLEFT_MOTOR});
MotorGroup rightMotors = MotorGroup({TOPRIGHT_MOTOR, BOTRIGHT_MOTOR});


void autonomous(){
  switch (autoSelector.startPos){
    case (startPosition::left_pole): {
      chassis1.driveStraight(5_in);
    }

    case (startPosition::middle_shortpole): {}

    case (startPosition::right_pole): {}

    case (startPosition::right_wallpole): {}

    case (startPosition::skills): {}

    case (startPosition::disabled): {}


  chassis1.driveStraight(48_in);
}

}
