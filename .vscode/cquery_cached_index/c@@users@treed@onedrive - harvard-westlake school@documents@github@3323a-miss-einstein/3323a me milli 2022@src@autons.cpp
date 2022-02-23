#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 127; // (110) This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

//set_lock6(IN);
//set_lock4(OUT);
//set_BaseClamp(IN);
//set_lift6bar_position(2, 127);
//set_lift4bar_position(2, 127);
//pto_intake(true);
//set_intake(127);

//Put new autons here!!

void skills_auton(){//SKILLLLLLLLLLLSSSSS AUTONNNNNNNNN

//grab and lift red mogo
set_lock6(OUT);
set_lock4(OUT);
pros::delay(300);
chassis.set_drive_pid(-5, 90);
chassis.wait_drive();
pros::delay(200);

set_lift4bar_position(24, 127);
set_lock6(IN);
set_lift6bar_position(298, 127);
pros::delay(300);

//drive to second mogo
chassis.set_drive_pid( 8, 90);
chassis.wait_drive();

chassis.set_turn_pid( 98, 90);
chassis.wait_drive();

//drive toward neutral goal 1
chassis.set_drive_pid( 65, 90);
chassis.wait_drive();

//grab onto neutral goal 1 and lift
set_lock4(IN);
pros::delay(100);
set_lift4bar_position(410, 127);

//drive to platform
chassis.set_turn_pid( 128, 90);
chassis.wait_drive();

chassis.set_drive_pid(53, 90);
chassis.wait_drive();

chassis.set_turn_pid(95, 127);
chassis.wait_drive();

//put neutral mogo 1 on plat
set_lift4bar_position(275, 127);
pros::delay(1500);

set_lock4(OUT);
pros::delay(300);

chassis.set_drive_pid(-2, 100);
chassis.wait_drive();

set_lift4bar_position(350, 127);
pros::delay(500);

chassis.set_drive_pid(-9, 90);
chassis.wait_drive();
set_lift4bar_position(20, 127);

//spin around and put aliance mogo #1 on plat
chassis.set_turn_pid(-85, 90);
chassis.wait_drive();

chassis.set_drive_pid(-9, 90);
chassis.wait_drive();

chassis.set_drive_pid(2, 90);

// drop blue mogo #1 on plat
set_lift6bar_position(250, 127);
set_lock6(OUT);

set_lift6bar_position(300, 127);
pros::delay(200);

chassis.set_drive_pid(1, 90);
chassis.wait_drive();

//drive to get red alliance mogo #1
chassis.set_turn_pid( 0, 90);
chassis.wait_drive();
set_lift6bar_position(0, 127);

chassis.set_drive_pid(47, 90);
chassis.wait_drive();

set_lock4(IN);

//get to yellow big neutral
set_lift6bar_position(0, 127);
chassis.set_drive_pid(-7, 90);
chassis.wait_drive();

set_lift4bar_position(375, 127);
pros::delay(200);

chassis.set_turn_pid(40, 90);
chassis.wait_drive();

chassis.set_drive_pid(-70, 90);
chassis.wait_drive();

//clamp onto big yellow neutral and lift
set_lock6(IN);
chassis.set_turn_pid(100, 80);
chassis.wait_drive();

set_lift6bar_position(325, 127);
pros::delay(200);

//drive to red plat
chassis.set_drive_pid(-33, 100);
chassis.wait_drive();
pros::delay(200);

set_lift6bar_position(198, 127);
pros::delay(600);

//release big yellow mogo on plat
set_lock6(OUT);
pros::delay(600);

chassis.set_drive_pid(3, 90);
chassis.wait_drive();

set_lift6bar_position(298, 127);
pros::delay(300);

//spin around to put red #1 on plat
chassis.set_turn_pid( 260, 90);
chassis.wait_drive();

chassis.set_drive_pid(5, 90);
pros::delay(300);

// put red on plat
set_lock4(OUT);
set_lift6bar_position(0, 127);
pros::delay(400);

//drive off of plat
chassis.set_drive_pid(-7, 90);
chassis.wait_drive();

//drive to get blue alliance mogo
chassis.set_turn_pid( 180, 90);
chassis.wait_drive();
set_lift4bar_position(20, 127);

chassis.set_drive_pid(51, 90);
chassis.wait_drive();
set_lock4(IN);

//back up to get yellow neutral #3
chassis.set_drive_pid(-17, 60);
pros::delay(400);
set_lift4bar_position(375, 127);
chassis.wait_drive();

chassis.set_turn_pid(270, 90);
chassis.wait_drive();

chassis.set_drive_pid(-37, 90);
chassis.wait_drive();

//Grab & lift neural goal #3
set_lock6(IN);
pros::delay(200);

set_lift6bar_position(298, 127);

//go to blue platform 2nd time
chassis.set_turn_pid(230, 80);
chassis.wait_drive();

chassis.set_drive_pid(-52, 90);
chassis.wait_drive();

//drop neutral goal #3 on platform
set_lock6(OUT);
pros::delay(300);

//spin around to place blue on plat
chassis.set_drive_pid(7, 90);
chassis.wait_drive();

chassis.set_turn_pid(75, 80);
chassis.wait_drive();
set_lift6bar_position(0, 127);

chassis.set_drive_pid(9, 90);
chassis.wait_drive();

set_lock4(OUT);
pros::delay(300);

//Get into position to get red mogo #2
chassis.set_drive_pid(-10, 90);
chassis.wait_drive();

chassis.set_turn_pid(180, 80);
chassis.wait_drive();
set_lift4bar_position(20, 127);

chassis.set_drive_pid(18, 90);
chassis.wait_drive();

//swing turn to red mogo #2
chassis.set_swing_pid(ez::RIGHT_SWING, 57, SWING_SPEED);
chassis.wait_drive();

//drive to red mogo #2
chassis.set_drive_pid(10, 90);
chassis.wait_drive();

//grab red mogo #2
set_lock4(IN);
pros::delay(300);

//drive back and lift
chassis.set_drive_pid(-22, 90);
chassis.wait_drive();

set_lift4bar_position(375, 127);
pros::delay(300);

//turn and drive to plat
chassis.set_turn_pid(90, 90);
chassis.wait_drive();

chassis.set_drive_pid(-117, 100);
chassis.wait_drive();

//turn to place
chassis.set_turn_pid(0, 80);
chassis.wait_drive();

chassis.set_drive_pid(11, 90);
chassis.wait_drive();
pros::delay(300);

//place last goal!!!!!!!
set_lift4bar_position(275, 90);
pros::delay(600);
set_lock4(OUT);
pros::delay(400);

//drive away...... IN VICTORYYYYYYYYYYYYYYY
chassis.set_drive_pid(-15, 100);
chassis.wait_drive();

//YAAAAAAYYYYYYYY!!!!!!!


}


void conveyor_check(){


  pto_intake(true);
  pros::delay(400);
  set_intake(127);
}

void the_steal(){

//lift 6 bar to get mogo in base grabby
set_lock6(OUT);
set_lift4bar_position(20, 10);
set_lift6bar_position(298, 127);
pros::delay(500);

/*
chassis.set_drive_pid(-16, 60);
chassis.wait_drive();

//get mogo in base grabby
set_BaseClamp(IN);
pros::delay(300);

//get in position to steal yellow neutral
chassis.set_drive_pid(10, 90);
chassis.wait_drive();

chassis.set_turn_pid(92, 80);
chassis.wait_drive();
*/

chassis.set_drive_pid(69,127);
chassis.wait_drive();

chassis.set_drive_pid(5.5,90);
chassis.wait_drive();

//grab onto yellow mogo
set_lock4(IN);
pros::delay(300);

//drive back in VICTORYYYYYY
chassis.set_drive_pid(-67, 127);
pros::delay(700);

set_lift4bar_position(375, 127);
chassis.wait_drive();

chassis.set_drive_pid(8, 5);

}



void solo_awp(){

//lift 6 bar to get mogo in base grabby
set_lock6(OUT);
set_lock4(OUT);
set_BaseClamp(OUT);

pto_intake(true);
set_lift4bar_position(49, 10);
set_lift6bar_position(298, 127);
pros::delay(200);

chassis.set_drive_pid(-16, 110);
chassis.wait_drive();

//get mogo in base grabby
set_intake(127);
pros::delay(600);

//get in position to drive across
pto_intake(false);
chassis.set_drive_pid(12, 110);
chassis.wait_drive();

chassis.set_turn_pid(90, 100);
chassis.wait_drive();

chassis.set_drive_pid(25, 110);
chassis.wait_drive();

chassis.set_turn_pid(0, 100);
chassis.wait_drive();

//drive across
chassis.set_drive_pid(-96, 127);
chassis.wait_drive();

chassis.set_drive_pid(-13, 80);
chassis.wait_drive();

//get aliance goal #2
set_BaseClamp(IN);
pros::delay(50);

// turn to get in position for pringles
chassis.set_drive_pid(9, 100);
chassis.wait_drive();

chassis.set_turn_pid(90, 100);
chassis.wait_drive();

pto_intake(true);
set_intake(100);
//start getting pringles

chassis.set_drive_pid(40 ,60);
chassis.wait_drive();

}

void pringle_neutral(){ //NEWWWWWW AUTONNNNNNNNNNNNNNNNNNNNNNN :))))))

//drive to neutral mogo
  set_lock6(OUT);
  set_BaseClamp(OUT);
  set_lift4bar_position(24, 127);

  chassis.set_drive_pid(-48, 127);
  chassis.wait_drive();

//clamp onto neutral mogo
  set_lock6(IN);
  pros::delay(100);

//lift neutral goal
  set_lift6bar_position(298, 127);
  pros::delay(200);

//get to aliance mogo
  chassis.set_drive_pid( 52, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid( 95, DRIVE_SPEED);
  chassis.wait_drive();


/*
  //get to pringle position
  chassis.set_drive_pid( 12, 100);
  chassis.wait_drive();

  chassis.set_turn_pid(180, 75);
  chassis.wait_drive();

  //get pringles
  pto_intake(true);
  set_intake(127);
  pros::delay(200);
  chassis.set_drive_pid( 30, 55);
  pros::delay(3000);
  set_intake(0);

  //go back home!
  chassis.wait_drive();
  chassis.set_drive_pid(-20, DRIVE_SPEED);
  chassis.wait_drive();

  */
}


///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .

void poopyscoopy() {

}
