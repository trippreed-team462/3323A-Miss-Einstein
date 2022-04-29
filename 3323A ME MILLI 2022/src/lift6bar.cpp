#include "main.h"


const int num_of_pos6 = 4; //number of lift6bar positions
const int lift6bar_heights[num_of_pos6] = {0, 310, 198, 310}; // lift6bar positions



//Driver Control Variables
int lift6bar_state = 0;
bool lift6_up = true;
bool lift6_down = true;
int lock6_lock = 0;
bool clamp6 = 0;
pros::ADIDigitalOut lock6_('D');

pros::Motor lift6bar(13, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);


void set_lift6bar(int input) { lift6bar = input; }

void zero_lift6bar()  { lift6bar.tare_position(); }
int get_lift6bar()    { return lift6bar.get_position(); }
int get_lift6bar_vel(){ return lift6bar.get_actual_velocity(); }

void
set_lift6bar_position(int target, int speed) {
  lift6bar.move_absolute(target, speed);
}

void set_lock6(int input)
{
  if(input ==IN)
 lock6_.set_value(true);
 if(input ==OUT)
  lock6_.set_value(false);
}

///
// Driver Control
// - when L1 is pressed, bring lift6bar up the position ladder
// - when L2 is pressed, bring lift6bar down the position ladder
///
void
lift6bar_control() {
   // lift6bar up
   if (partner.get_digital(DIGITAL_R1) && lift6_up==0) {
     // if lift6bar is at max height, bring it down to 0
     if(lift6bar_state==num_of_pos6-1)
      lift6bar_state = 0;
    // Otherwise, bring lift up
    else
     lift6bar_state++;

    lift6_up = 1;
    set_lift6bar_position(lift6bar_heights[lift6bar_state], 100);
}
else if (!partner.get_digital(DIGITAL_R1)) {
  lift6_up = 0;
}

// lift6bar down
if (partner.get_digital(DIGITAL_L1) && lift6_down==0) {
  // if lift4bar is at max height, bring it down to 0
  if(lift6bar_state==0)
   lift6bar_state = num_of_pos6 -1;
 // Otherwise, bring lift4bar down
 else
  lift6bar_state--;

 lift6_down = 1;
 set_lift6bar_position(lift6bar_heights[lift6bar_state], 100);
}
else if (!partner.get_digital(DIGITAL_L1)) {
lift6_down = 0;
}





// Set the Lift6bar to the current position in the array

}

int timer6 = 0;
void
lock6_control(){
  //toggle for lock4
  if (partner.get_digital(DIGITAL_R2) && lock6_lock==0) {
    clamp6 = !clamp6;
  set_lock6(clamp6);
  lock6_lock = 1;

 }
   else if (!partner.get_digital(DIGITAL_R2))
   lock6_lock = 0;
}
