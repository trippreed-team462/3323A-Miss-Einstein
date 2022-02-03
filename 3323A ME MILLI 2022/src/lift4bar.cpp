#include "main.h"




const bool IN = true;
const bool OUT = false;


//Driver Control Variables
int lift4bar_state = 0;
bool lift4_up = true;
bool lift4_down = true;
int lock4_lock = 0;
bool clamp4 = true;
pros::ADIDigitalOut lock4('F');

pros::Motor lift4bar(10, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);


void set_lift4bar(int input) { lift4bar = input; }

void zero_lift4bar()  { lift4bar.tare_position(); }
int get_lift4bar()    { return lift4bar.get_position(); }
int get_lift4bar_vel(){ return lift4bar.get_actual_velocity(); }

void
set_lift4bar_position(int target, int speed) {
  lift4bar.move_absolute(target, speed);
}

void set_lock4(int input)
{
  if(input == IN)
  lock4.set_value(true);
  if(input ==OUT)
  lock4.set_value(false);
}
///
// Driver Control
// - when R1 is pressed, bring lift4bar up the position ladder
///

void
lift4bar_control() {
   // lift6bar up
   if (master.get_digital(DIGITAL_R1) && lift4_up==0) {
     // if lift4bar is at max height, bring it down to 0
     if(lift4bar_state==num_of_pos-1)
      lift4bar_state = 0;
    // Otherwise, bring lift4bar up
    else
     lift4bar_state++;

    lift4_up = 1;
  }
  else if (!master.get_digital(DIGITAL_R1)) {
  lift4_up = 0;
}

// lift6bar down
if (master.get_digital(DIGITAL_L1) && lift4_down==0) {
  // if lift4bar is at max height, bring it down to 0
  if(lift4bar_state==0)
   lift4bar_state = num_of_pos -1;
 // Otherwise, bring lift4bar down
 else
  lift4bar_state--;

 lift4_down = 1;
}
else if (!master.get_digital(DIGITAL_L1)) {
lift4_down = 0;
}

// Lift4bar down


// Set the Lift4bar to the current position in the array
  set_lift4bar_position(lift4bar_heights[lift4bar_state], 100);
}

int timer4 = 0;
void
lock4_control(){
  //toggle for lock4
  if (master.get_digital(DIGITAL_R2) && lock4_lock==0) {
    clamp4 = !clamp4;
    set_lock4(clamp4);
      lock4_lock = 1;
  }
  else if (!master.get_digital(DIGITAL_R2))
  lock4_lock = 0;

}
