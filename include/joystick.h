#ifndef joystick_H
#define joystick_H


#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <map>
#include <chrono>
#include <condition_variable> // std::condition_variable
#include "joystick_linux.h"
#include <unistd.h>
#include "message.h"
#include "gui.h"



class joystick{
public:
  // Create an instance of Joystick
  Joystick jstick;

  joystick(message* msg);
  ~joystick();

  void read(message*,i3DEDGE_GUI* caller);

};

#endif
