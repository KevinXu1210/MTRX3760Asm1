// turtlebot3_lidar.cpp

#include "turtlebot3_gazebo/turtlebot3_lidar.h"

//subscribe from the lidar scan
void Turtlebot3Drive::laserScanMsgCallBack(const sensor_msgs::LaserScan::ConstPtr &msg)
{
  uint16_t scan_angle[5] = {0, 40, 90, 270, 320};

  for (int num = 0; num < 5; num++)
  {
    if (std::isinf(msg->ranges.at(scan_angle[num])))
    {
      scan_data_[num] = msg->range_max;
    }
    else
    {
      scan_data_[num] = msg->ranges.at(scan_angle[num]);
    }

    ROS_INFO("center %f", scan_data_[0]);
    ROS_INFO("left_front %f", scan_data_[1]);
    ROS_INFO("left %f", scan_data_[2]);
    ROS_INFO("right %f", scan_data_[3]);
    ROS_INFO("right_front %f", scan_data_[4]);
  }
}

//ros::Subscriber laser_scan_sub_  = nh_.subscribe("scan", 10, &Turtlebot3Drive::laserScanMsgCallBack, this);
