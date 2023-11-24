#ifndef drone_H
#define drone_H

#include "tello.hpp"
#include "message.h"
#include "gui.h"

class drone{
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  Tello* tello;
  double max_distance_step=50;
  double max_angle_step=50;
  double input_th=0.2;
  double drone_min_input=20; //cm


  drone(message* msg);
  ~drone();

  void connect(message* msg);
  void takeoff();
  void land();
  void left(double);
  void right(double);
  void fwd(double);
  void bwd(double);
  void up(double d);
  void dwn(double d);
  void rotate(double);
  void stream_on(message* msg);
  void stream(message* msg,i3DEDGE_GUI* caller);
  void stop();
  void transmit(message* msg);

};

#endif
