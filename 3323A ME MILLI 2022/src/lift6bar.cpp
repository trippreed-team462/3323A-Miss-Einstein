#include "main.h"


const int num_of_pos = 4; //number of lift6bar positions
const int lift6bar_heights[num_of_pos] = {0, 500, 310, 500}; // lift6bar positions
const bool IN = true;
const bool OUT = false;


//Driver Control Variables
int lift6bar_state = 0;
bool lock6_up = true;
int lock6_lock = 0;
int lock6 = 0;
pros::ADIDigitalOut lock6_('B');

pros::Motor lift6bar(13, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);


void set_lift6bar(int input) { lift6bar = input; }

void zero_lift6bar()  { lift6bar.tare_position(); }
int get_lift6bar()    { return lift6bar.get_position(); }
int get_lift6bar_vel(){ return lift6bar.get_actual_velocity(); }

void
set_lift6bar_position(int target, int speed) {
  lift6bar.move_absolute(target, speed);
}

//void set_lock6(int input)
//{
  //if(input ==IN)
  lock6_.set_value(true)
//  if(input ==OUT)
  lock6_.set_value(false)
//}

///
// Driver Control
// - when L1 is pressed, bring lift6bar up the position ladder
// - when L2 is pressed, bring lift6bar down the position ladder
///
void
lift6bar_control() {
   // lift6bar up
   if (master.get_digital(DIGITAL_L1) && lock6_up==0) {
     // if lift6bar is at max height, bring it down to 0
     if(lift6bar_state==num_of_pos-1)
      lift6bar_state = 0;
    // Otherwise, bring lift up
    else
     lift6bar_state++;

    lock6_up = true;
}
else if (!master.get_digital(DIGITAL_L1)) {
  lock6_up = 0;
}

// Lift6bar down

// Set the Lift6bar to the current position in the array
  set_lift6bar_position(lift6bar_heights[lift6bar_state], 100);
}

int timer6 = 0;
void
lock6_control(){
  //toggle for lock4
  if (master.get_digital(DIGITAL_R2) && lock6==0) {
  //  set_lock6_(false);
    if(timer6 >= 20)
    {
      lock6 = true;
      timer6 = 0;
    }
    printf("out");

  }
    printf("timer6 = %d \n", timer6);
      timer6++;
}
