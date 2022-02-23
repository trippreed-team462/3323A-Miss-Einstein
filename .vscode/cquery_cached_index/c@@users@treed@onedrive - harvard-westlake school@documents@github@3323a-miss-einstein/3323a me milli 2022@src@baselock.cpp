#include "main.h"


//Driver Control Variables
bool BaseClamp = true;
int BaseLock = 0;
pros::ADIDigitalOut Basegrabby('H');
pros::ADIDigitalIn  basegrabbylimit ('A');


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


  if (BaseLock == false && basegrabbylimit.get_value() == true){
    BaseClamp = true;
    set_BaseClamp(BaseClamp);
  }

}
