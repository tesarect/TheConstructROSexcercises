#include "robot_commander/robot_commander.h"
#include <iomanip>
#include <iostream>
#include <ros/ros.h>
#include <set>

// Structure to represent a 2D point
struct Point {
  float x, y;

  Point(float x_val, float y_val) : x(x_val), y(y_val) {}

  // Comparison operator for set ordering
  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }

  // Equality operator for comparison
  bool operator==(const Point &other) const {
    return (std::abs(x - other.x) < 0.01) && (std::abs(y - other.y) < 0.01);
  }
};

// Function to print a point
std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "(" << std::fixed << std::setprecision(2) << p.x << ", " << p.y << ")";
  return os;
}

int main(int argc, char **argv) {
  // Initialize ROS node
  ros::init(argc, argv, "path_coordinates_node");

  // Create RobotCommander object
  RobotCommander robot;

  // Containers to store coordinates
  std::set<Point> coordinate_set;
  std::multiset<Point> coordinate_multiset;

  ROS_INFO("Starting polygonal path tracing - Creating a square");

  // Wait a moment for initialization
  ros::Duration(1.0).sleep();

  // Store initial position
  float start_x = robot.get_x_position();
  float start_y = robot.get_y_position();
  Point start_point(start_x, start_y);

  coordinate_set.insert(start_point);
  coordinate_multiset.insert(start_point);

  std::cout << "Starting position: " << start_point << std::endl;

  // Trace a square path (4 vertices)
  int side_duration = 3;      // seconds to move forward
  float turn_velocity = 1.57; // ~90 degrees in rad/s (π/2)
  int turn_duration = 1;      // 1 second turn

  for (int i = 0; i < 4; i++) {
    ROS_INFO("Moving forward for side %d", i + 1);

    // Move forward
    robot.move_forward(side_duration);

    // Get current position after moving
    float current_x = robot.get_x_position();
    float current_y = robot.get_y_position();
    Point current_point(current_x, current_y);

    // Store coordinates
    coordinate_set.insert(current_point);
    coordinate_multiset.insert(current_point);

    std::cout << "Vertex " << (i + 1) << ": " << current_point << std::endl;

    // Turn left (counterclockwise) for next side
    if (i < 3) { // Don't turn after the last side
      ROS_INFO("Turning left");
      robot.turn(turn_velocity, turn_duration);
      ros::Duration(0.5).sleep(); // Small pause after turn
    }
  }

  // Return to starting position
  ROS_INFO("Returning to start position");
  robot.move_forward(side_duration);

  // Get final position
  float final_x = robot.get_x_position();
  float final_y = robot.get_y_position();
  Point final_point(final_x, final_y);

  // Add final position (should be close to start)
  coordinate_set.insert(final_point);
  coordinate_multiset.insert(final_point);

  std::cout << "Final position: " << final_point << std::endl;

  // Stop the robot
  robot.stop_moving();

  // Print results using SET
  std::cout << "\n=== COORDINATES STORED IN SET ===" << std::endl;
  std::cout << "Set size: " << coordinate_set.size() << std::endl;
  std::cout << "Set contents:" << std::endl;
  int count = 1;
  for (const auto &point : coordinate_set) {
    std::cout << count++ << ". " << point << std::endl;
  }

  // Add some duplicate points to demonstrate multiset behavior
  coordinate_multiset.insert(start_point); // Add duplicate start point
  coordinate_multiset.insert(
      Point(final_x, final_y)); // Add duplicate final point

  // Print results using MULTISET
  std::cout << "\n=== COORDINATES STORED IN MULTISET ===" << std::endl;
  std::cout << "Multiset size: " << coordinate_multiset.size() << std::endl;
  std::cout << "Multiset contents:" << std::endl;
  count = 1;
  for (const auto &point : coordinate_multiset) {
    std::cout << count++ << ". " << point << std::endl;
  }

  // Explain the difference
  std::cout << "\n=== DIFFERENCE BETWEEN SET AND MULTISET ===" << std::endl;
  std::cout << "SET:" << std::endl;
  std::cout << "- Only stores unique elements" << std::endl;
  std::cout << "- Duplicate coordinates are automatically removed" << std::endl;
  std::cout << "- Size: " << coordinate_set.size() << std::endl;

  std::cout << "\nMULTISET:" << std::endl;
  std::cout << "- Allows duplicate elements" << std::endl;
  std::cout << "- Same coordinates can appear multiple times" << std::endl;
  std::cout << "- Size: " << coordinate_multiset.size() << std::endl;

  ROS_INFO("Path tracing completed!");

  return 0;
}