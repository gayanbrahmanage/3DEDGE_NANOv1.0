
#include "joystick.h"
#include "drone.h"


int main(int argc, char **argv){

  parameters* param=new parameters();

  auto app = Gtk::Application::create(argc, argv, "GayanBrahmanage");
  i3DEDGE_GUI gui;

  joystick* jinput=new joystick(gui.msg);
  std::thread jinput_thread(&joystick::read,jinput,gui.msg,&gui);

  drone* uav=new drone(gui.msg);
  std::thread uav_thread(&drone::stream,uav,gui.msg,&gui);
  std::thread uav_tr_thread(&drone::transmit,uav,gui.msg);
  
  app->run(gui);

  jinput_thread.join();
  uav_thread.join();
  uav_tr_thread.join();
  return 0;
}
