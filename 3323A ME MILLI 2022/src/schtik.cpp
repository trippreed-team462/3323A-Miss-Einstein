#include "main.h"


//Driver Control Variables
bool schtik = true;
int schtikB = 0;
pros::ADIDigitalOut schtikA('G');
//pros::ADIDigitalIn  basegrabbylimit ('A');

void set_schtik(int input)
{
  if(input == IN)
  schtikA.set_value(false);
  if(input == OUT)
  schtikA.set_value(true);
}

void
schtikA_control()
{
  //toggle for lock4
  if (master.get_digital(DIGITAL_B) && schtikB==0) {
    schtik = !schtik;
     schtikA.set_value(schtik);
     schtikB = 1;
     printf("in the if");
  }
  else if (!master.get_digital(DIGITAL_B))
  schtikB = 0;


  //if (schtik == false && schtiklimit.get_value() == true){
  //  schtik = true;
  //  set_schtik(schtik);
  }
