  switch(turtlebot3_state_num)
  {
    case GET_TB3_DIRECTION:

        // no wall ahead
        if (scan_data_[CENTER] > check_forward_dist_  || scan_data_[LEFT] > check_forward_dist_)
        {
          prev_tb3_pose_ = tb3_pose_;
                
          if (scan_data_[LEFT] > min_left_dist_ && scan_data_[TOP_LEFT] > max_left_dist_)
          {
            prev_tb3_pose_ = tb3_pose_;
            turtlebot3_state_num = TB3_ADJUST_LEFT;
            std::cout << "ADJUST TO LEFT" << std::endl;
          }
          
          else if (scan_data_[TOP_LEFT] < min_left_dist_ && scan_data_[LEFT] < min_left_dist_)
          {
            prev_tb3_pose_ = tb3_pose_;

            turtlebot3_state_num = TB3_ADJUST_RIGHT;
            std::cout << "ADJUST TO RIGHT" << std::endl;
          }

          // if within a certain range, follow the path
          else
          {
            // update tb3 position
            prev_tb3_pose_ = tb3_pose_;
            turtlebot3_state_num = TB3_DRIVE_FORWARD;
            std::cout << "DRIVE FORWARD" << std::endl;
          }
        }

        // obstacle ahead
        else if (scan_data_[CENTER] < check_forward_dist_  && (scan_data_[TOP_RIGHT] < check_forward_dist_))
        {
          if (scan_data_[LEFT] > scan_data_[RIGHT] )
          {
            prev_tb3_pose_ = tb3_pose_;
            turtlebot3_state_num = TB3_LEFT_TURN;
            std::cout << "LEFT" << std::endl;
          }
          else if (scan_data_[LEFT] < scan_data_[RIGHT])
          {
            prev_tb3_pose_ = tb3_pose_;
            turtlebot3_state_num = TB3_RIGHT_TURN;
            std::cout << "RIGHT" << std::endl;
          }
        }
      break;
    
    case TB3_DRIVE_FORWARD:
      turtlebot3_state_num = GET_TB3_DIRECTION;
      updatecommandVelocity(1.5 * LINEAR_VELOCITY, 0.0);
      break;

    case TB3_ADJUST_LEFT:
      if (fabs(prev_tb3_pose_ - tb3_pose_) >= escape_range_adjust)
        {
          // drive forward after turn
          updatecommandVelocity(LINEAR_VELOCITY , 0.0);
          ros::Duration(SLEEP_DURATION).sleep();
        turtlebot3_state_num = GET_TB3_DIRECTION;
        }
      else
        {
          updatecommandVelocity(0.0,  ANGULAR_VELOCITY);
        }
      break;

    case TB3_ADJUST_RIGHT:

      if (fabs(prev_tb3_pose_ - tb3_pose_) >= escape_range_adjust)
        {
          updatecommandVelocity(0.0, 0.0);
          // drive forward after turn
          updatecommandVelocity( LINEAR_VELOCITY, 0.0);
          ros::Duration(SLEEP_DURATION).sleep();
        turtlebot3_state_num = GET_TB3_DIRECTION;
        }

      else
        {
          updatecommandVelocity(0.0, -1 * ANGULAR_VELOCITY);
        }
        
      break;   

    default:
      turtlebot3_state_num = GET_TB3_DIRECTION;
      break;
  }
