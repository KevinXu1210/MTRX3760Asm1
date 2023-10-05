// turtlebot3_cmdvel.h

#ifndef TURTLEBOT3_CMDVEL_H_
#define TURTLEBOT3_CMDVEL_H_

#include <ros/ros.h>

#include <geometry_msgs/Twist.h>

#define DEG2RAD (M_PI / 180.0)
#define RAD2DEG (180.0 / M_PI)

// Linear and angular velocities published to cmd_vel
#define LINEAR_VELOCITY  0.3
#define ANGULAR_VELOCITY 1

// List of linear and angular velocity command sets
#define START 0
#define GET_TB3_DIRECTION 1
#define TB3_DRIVE_FORWARD 2
#define TB3_RIGHT_TURN    3
#define TB3_LEFT_TURN     4
#define TB3_CORNER_IN    5
#define TB3_CORNER_OUT     6

// Class for angular and linear velocity commands
class Turtlebot3CmdVel
{
 private:
  // ROS NodeHandle
  ros::NodeHandle nh_;
  ros::NodeHandle nh_priv_;

  // ROS Topic Publishers
  ros::Publisher cmd_vel_pub_;

  // Function prototype for command velocity
  void updatecommandVelocity(double linear, double angular);
};

#endif // TURTLEBOT3_CMDVEL_H_
