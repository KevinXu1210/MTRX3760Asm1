// turtlebot3_cmdvel.cpp

#include "turtlebot3_gazebo/turtlebot3_cmdvel.h"

// Publish velocity commands 
void Turtlebot3Drive::updatecommandVelocity(double linear, double angular)
{
  geometry_msgs::Twist cmd_vel;

  cmd_vel.linear.x  = linear;
  cmd_vel.angular.z = angular;

  cmd_vel_pub_.publish(cmd_vel);
}

//ros::Publisher cmd_vel_pub_   = nh_.advertise<geometry_msgs::Twist>(cmd_vel_topic_name, 10);
