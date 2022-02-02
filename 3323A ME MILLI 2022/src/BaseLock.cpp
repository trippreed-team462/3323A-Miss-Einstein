#include "main.h"

const int IN = true;
const int OUT = false;

//Driver Control Variables
bool BaseClamp = true;
int BaseLock = 0;
pros::ADIDigitalOut Basegrabby('H');


void set_BaseClamp(int input)
{
  if(input == IN)
  Basegrabby.set_value(true);
  if(input ==OUT)
  Basegrabby.set_value(false);
}


void
Basegrabby_control(){
  //toggle for lock4
  if (master.get_digital(DIGITAL_L2) && BaseLock==0) {
    BaseClamp = !BaseClamp;
    set_BaseClamp(BaseClamp);
     BaseLock = 1;
  }
  else if (!master.get_digital(DIGITAL_L2))
  BaseLock = 0;

}
