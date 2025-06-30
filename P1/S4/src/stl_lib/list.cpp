#include <forward_list>
#include <iostream>
#include <list>

using namespace std;

int main() {

  list<string> laserL{"range_max", "range_min", "angle_max", "angle_min"};
  forward_list<string> laserFL{"range_max", "range_min", "angle_max",
                               "angle_min"};

  // iterator laser_front starts to point the first element of the list
  auto laser_front_L = laserL.begin();
  auto laser_front_FL = laserFL.begin();

  // Jump 2 more times as you are already on the first element
  advance(laser_front_L, 2);
  advance(laser_front_FL, 2);
  // * is used to tell the value of what is being pointed by the iterator
  cout << *laser_front_L << '\n';
  cout << *laser_front_FL << '\n';

  // iterator laser_front starts to point the past-the-end element of the list
  laser_front_L = laserL.end();
  laser_front_FL = laserFL.end();

  // Jump back to the third element from last
  laser_front_L = next(laser_front_L, -3);
  cout << *laser_front_L << '\n';

  laser_front_FL = next(laser_front_FL, -3);
  cout << *laser_front_FL << '\n';

  return 0;
}
