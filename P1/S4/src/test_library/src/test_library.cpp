#include "../include/test_library/test_library.h"

void display_pos(float x, float y) {

  float pos_x = x;
  float pos_y = y;
  std::cout << "Pos X: " << pos_x << " Pos Y: " << pos_y << std::endl;
}

void Calculation(float lin, float ang) {
  std::cout << "Linear velocity:" << lin << "Angular Velocity:" << ang
            << std::endl;
}