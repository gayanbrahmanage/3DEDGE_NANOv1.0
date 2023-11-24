#ifndef message_H
#define message_H

#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <map>
#include <chrono>
#include <condition_variable> // std::condition_variable
#include <Eigen/Core>

struct axis_calib{
  int max=32767;
  int min=-32767;
  int mid=0;
};

struct joystic_message{

  axis_calib axis0calib;
  axis_calib axis1calib;
  axis_calib axis2calib;
  axis_calib axis3calib;
  axis_calib axis4calib;
  axis_calib axis5calib;

  int axis0_value=0;
  double axis0_Nvalue=0;
  int axis1_value=0;
  double axis1_Nvalue=0;
  int axis2_value=0;
  double axis2_Nvalue=0;
  int axis3_value=0;
  double axis3_Nvalue=0;
  int axis4_value=0;
  double axis4_Nvalue=0;
  int axis5_value=0;
  double axis5_Nvalue=0;

  bool button0=false;
  bool button1=false;
  bool button2=false;
  bool button3=false;
  bool button4=false;
  bool button5=false;
  bool button6=false;
  bool button7=false;
  bool button8=false;
  bool button9=false;
  bool button10=false;
  bool button11=false;

};

struct message{

  joystic_message jstk;
  cv::Mat cam_image;
  bool Connect_EN=false;
  bool connected=false;
  bool app_launched=false;
  //bool Input_connected=false;
  bool video_stream_EN=false;
  bool video_stream_on=false;
  bool show_cam_or_3D=true;
  bool good_frame=false;

  std::mutex drone_read;
  std::mutex jstick_read;
  std::mutex drone_transmit;

  //input commandServer
  bool command_TakeOFF=false;
  bool command_Land=false;
  bool command_Manual=false;
  bool command_Up=false;
  bool command_Down=false;
  bool command_Left=true;
  bool command_Right=false;
  bool command_Forward=false;
  bool command_Back=false;
  bool command_RotateC=false;
  bool command_RotateA=false;
  bool command_Move=false;
  bool command_Flip=false;
  bool command_Stop=false;
  bool command_Idle=false;
  bool command_TakeScreeenShot=true;
  bool joystick_connected=false;

  // functions
  bool AIdepthOn=false;
  bool DetectorON=false;

};

#endif
