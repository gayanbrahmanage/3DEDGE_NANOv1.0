#ifndef parameters_H
#define parameters_H
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <Eigen/Core>
#include <vector>
#include <mutex>
#include <map>
#include <chrono>
#include <condition_variable> // std::condition_variable

class parameters{
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  int gui_width=1460;
  int gui_height=920;
  int video_width=960;
  int video_height=720;
  cv::Scalar gui_b_color=cv::Scalar(16,16,16);
  cv::Scalar gui_panel_color=cv::Scalar(28,28,28);

  cv::Scalar control_button_manual=cv::Scalar(0,128,0);
  cv::Scalar control_button_auto=cv::Scalar(0,0,128);

  cv::Scalar button_idle=cv::Scalar(40,40,40);
  cv::Scalar command_on=cv::Scalar(128,0,0);
  cv::Scalar command_move_on=cv::Scalar(0,128,0);
  cv::Scalar command_stop_on=cv::Scalar(0,0,128);
  cv::Scalar command_idel_on=cv::Scalar(0,128,128);

  cv::Scalar STATUS_on=cv::Scalar(0,128,0);
  cv::Scalar STATUS_off=cv::Scalar(64,64,0);
  cv::Scalar STATUS_Warning=cv::Scalar(128,128,0);



  parameters();
  ~parameters();

};

#endif
