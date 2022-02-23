#pragma once

void set_lift6bar(int input);
void zero_lift6bar();
int get_lift6bar();
int get_lift6bar_vel();

void lift6bar_control();
void lock6_control();
void set_lift6bar_position(int target, int speed);
const bool IN = true;
const bool OUT = false;
void set_lock6(int input);
