#include "main.h"


const int num_of_pos = 4; //number of lift4bar positions
const int lift4bar_heights[num_of_pos] = {0, 500, 310, 500}; // lift4bar positions
const int IN = 1;
const int OUT = 2;


//Driver Control Variables
int lift4bar_state = 0;
bool lock4_up = true;
int lock4_lock = 0;

pros::Motor lift4bar(10, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);
pros::ADIDigitalOut lock4(6);

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
   if (master.get_digital(DIGITAL_R1) && lock4_up==0) {
     // if lift4bar is at max height, bring it down to 0
     if(lift4bar_state==num_of_pos-1)
      lift4bar_state = 0;
    // Otherwise, bring lift4bar up
    else
     lift4bar_state++;

    lock4_up = 1;
}
else if (!master.get_digital(DIGITAL_R1)) {
  lock4_up = 0;
}

// Lift4bar down

// Set the Lift4bar to the current position in the array
  set_lift4bar_position(lift4bar_heights[lift4bar_state], 100);
}

int timer = 0;
void
lock4_control(){
  //toggle for lock4
  if (master.get_digital(DIGITAL_R2) && lock4_lock==0) {
    set_lock4(OUT);
    if(timer >= 20)
    {
      lock4_lock = 1;
      timer = 0;
    }
    printf("out");

  }
    printf("timer = %d \n", timer);
      timer++;
}
