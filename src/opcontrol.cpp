#include "main.h"
#include "okapi/api.hpp"

using namespace okapi;

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stoped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
	const int LEFTLIFT_MOTOR = 11;
	const int RIGHTLIFT_MOTOR = 1;
	const int TOPLEFT_MOTOR = 9;
	const int TOPRIGHT_MOTOR = 10;
	const int BOTRIGHT_MOTOR = 19;
	const int BOTLEFT_MOTOR = 20;
	

	const int NUM_HEIGHTS = 3;
	const int height1 = 200;
	const int height2 = 600;
	const int height3 = 1000;
	const int heights[NUM_HEIGHTS] = {height1, height2, height3};

	auto drive = ChassisModelFactory::create(TOPLEFT_MOTOR, BOTLEFT_MOTOR,  BOTRIGHT_MOTOR, TOPRIGHT_MOTOR, 200, 12000);

	auto liftControl = AsyncControllerFactory::posIntegrated({LEFTLIFT_MOTOR, RIGHTLIFT_MOTOR});

	ControllerButton btnUp(ControllerDigital::A);
	ControllerButton btnDown(ControllerDigital::B);
	ControllerButton btnBackUp(ControllerDigital::R1);
	ControllerButton btnBackDown(ControllerDigital::R2);


void opcontrol() {
	Controller masterController;
	int goalHeight = 0;

	  while (true) {
			int power = masterController.getAnalog(ControllerAnalog::leftY);
			int strafe = masterController.getAnalog(ControllerAnalog::leftX);
			int turn = masterController.getAnalog(ControllerAnalog::rightX);

			drive.xArcade(power, turn, strafe);


    if (btnUp.changedToPressed() && goalHeight < NUM_HEIGHTS - 1) {
      goalHeight++;
      liftControl.setTarget(heights[goalHeight]);
    }
		else if (btnDown.changedToPressed() && goalHeight > 0) {
      goalHeight--;
      liftControl.setTarget(heights[goalHeight]);
    }
	    // Wait and give up the time we don't need to other tasks.
	    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
	    pros::delay(10);
	  }
	}
