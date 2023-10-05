// turtlebot3_odom.h

#ifndef TURTLEBOT3_ODOM_H_
#define TURTLEBOT3_ODOM_H_

#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

// Odometry class for Turtlebot movements 
class Turtlebot3Odom
{
 private:
  // ROS NodeHandle
  ros::NodeHandle nh_;
  ros::NodeHandle nh_priv_;

  // ROS Topic Subscriber
  ros::Subscriber odom_sub_;

  // TB3 ODOMETRY POSITION
  double tb3_pose_;
  double prev_tb3_pose_;

  // Function prototype for odometry
  void odomMsgCallBack(const nav_msgs::Odometry::ConstPtr &msg);
};

#endif // TURTLEBOT3_ODOM_H_
