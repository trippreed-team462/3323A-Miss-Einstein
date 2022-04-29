#include "main.h"



// Driver Control Variables


pros::Motor& intake_l = chassis.left_motors[2];
pros::Motor& intake_r = chassis.right_motors[2];
pros::ADIDigitalOut pto_intake_piston('B');
bool pto_intake_enabled = true;

void pto_intake(bool toggle) {
  pto_intake_enabled = toggle;
  chassis.pto_toggle({intake_l, intake_r}, toggle);
  pto_intake_piston.set_value(!toggle);
  if (toggle) {
    intake_l.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake_r.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  }
}

void set_intake(int input) {
  if (!pto_intake_enabled) return;
  intake_l = input;
  intake_r = input;
}


int button_lock = 0;
void intake_control() {
  if (master.get_digital(DIGITAL_DOWN) && button_lock == 0) {
    pto_intake(!pto_intake_enabled);
    button_lock = 1;
  } else if (!master.get_digital(DIGITAL_DOWN)) {
    button_lock = 0;
  }

  if (partner.get_digital(DIGITAL_L2))
  {
    pto_intake(true);
    set_intake(121);
  }
  else if (partner.get_digital(DIGITAL_B))
    set_intake(-127);
  else
    set_intake(0);
    //printf("%i\n", pto_intake_enabled);
}
