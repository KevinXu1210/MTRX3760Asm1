// turtlebot3_lidar.h

#ifndef TURTLEBOT3_LIDAR_H_
#define TURTLEBOT3_LIDAR_H_

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

#define DEG2RAD (M_PI / 180.0)
#define RAD2DEG (180.0 / M_PI)

// 5 angles from the lidar scanner is used: center(front), left, right, left front, right front
#define CENTER    0
#define LEFT_F    1
#define LEFT      2
#define RIGHT     3
#define RIGHT_F   4

// class for lidar scans
class Turtlebot3Lidar
{
 private:
  // ROS NodeHandle
  ros::NodeHandle nh_;
  ros::NodeHandle nh_priv_;

  // ROS Topic Subscriber
  ros::Subscriber laser_scan_sub_;

  // Array to store scan data
  double scan_data_[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

  // Function prototype
  void laserScanMsgCallBack(const sensor_msgs::LaserScan::ConstPtr &msg);
};

#endif 

// TURTLEBOT3_LIDAR_H_
