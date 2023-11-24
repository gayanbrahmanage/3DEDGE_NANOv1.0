#include "joystick.h"

joystick::joystick(message* msg){
  // Ensure that it was found and that we can use it
  if (!jstick.isFound()){
    printf("open failed.\n");
    msg->joystick_connected=false;
  }else{
    std::cout<<"joystick connected"<<std::endl;
    msg->joystick_connected=true;
  }
}

joystick::~joystick(){

}

void joystick::read(message* msg, i3DEDGE_GUI* caller){

  while(msg->joystick_connected){

    // Restrict rate
    usleep(1000);
    // Attempt to sample an event from the joystick
    JoystickEvent event;

    //std::cout<<"JOY STICK"<<std::endl;

    if (jstick.sample(&event)){
      std::cout<<"JOY STICK"<<std::endl;
      if (event.isButton()){
        std::lock_guard<std::mutex> lock(msg->jstick_read);
          printf("Button %u is %s\n",
            event.number,
            event.value == 0 ? "up" : "down");

          if(event.number==0) {
            msg->jstk.button0=event.value;

          }else if(event.number==1) {
            msg->jstk.button1=event.value;

          }else if(event.number==2) {
            msg->jstk.button2=event.value;

          }else if(event.number==3) {
            msg->jstk.button3=event.value;

          }else if(event.number==4) {
            msg->jstk.button4=event.value;

          }else if(event.number==5) {
            msg->jstk.button5=event.value;

          }else if(event.number==6) {
            msg->jstk.button6=event.value;

          }else if(event.number==7) {
            msg->jstk.button7=event.value;

          }else if(event.number==8) {
            msg->jstk.button8=event.value;

          }else if(event.number==9) {
            msg->jstk.button9=event.value;

          }else if(event.number==10) {
            msg->jstk.button10=event.value;

          }else if(event.number==11) {
            msg->jstk.button11=event.value;

          }else{

          }

      }
      else if (event.isAxis()){
        printf("Axis %u is at position %d\n", event.number, event.value);

        if(event.number==0) {
          msg->jstk.axis0_value=event.value;

        }else if(event.number==1) {
          msg->jstk.axis1_value=event.value;

        }else if(event.number==2) {
          msg->jstk.axis2_value=event.value;

        }
        else if(event.number==3) {
          msg->jstk.axis3_value=event.value;

        }else if(event.number==4) {
          msg->jstk.axis4_value=event.value;

        }else if(event.number==5) {
          msg->jstk.axis5_value=event.value;

        }else{

        }

      }

      caller->connect(msg);

    }
  }
}
