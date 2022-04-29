#pragma once

inline const int num_of_pos = 4; //number of lift4bar positions
inline const int lift4bar_heights[num_of_pos] = {20, 375, 266 ,375}; // lift4bar positions

void set_lift4bar(int input);
void zero_lift4bar();
int get_lift4bar();
int get_lift4bar_vel();

void set_lock4(int input);
void lift4bar_control();
void lock4_control();
void set_lift4bar_position(int target, int speed);
