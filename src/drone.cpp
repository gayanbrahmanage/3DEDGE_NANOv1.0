#include "drone.h"

drone::drone(message* msg){

}

drone::~drone(){

}

void drone::connect(message* msg){

  std::lock_guard<std::mutex> lock(msg->drone_read);
  if (tello->connect()) {
      std::cout<<" Drone  connected "<< std::endl;
      msg->connected=true;

  }else{
      std::cout<<" Drone  Not connected "<< std::endl;
      msg->connected=false;
  }

}

void drone::takeoff(){
  tello->takeoff();
}

void drone::land(){
  tello->land();
}

void drone::left(double d){
  tello->move_left(d);
}
void drone::right(double d){
  tello->move_right(d);
}
void drone::fwd(double d){
  tello->move_forward(d);
}
void drone::bwd(double d){
  tello->move_back(d);
}

void drone::up(double d){
  tello->move_up(d);
}

void drone::dwn(double d){
  tello->move_down(d);
}

void drone::rotate(double d){
  if(d>0)
    tello->turn_right(d);
  else
    tello->turn_left(-d);
}

void drone::stop(){
  tello->stop();
}

void drone::stream_on(message* msg){
  std::lock_guard<std::mutex> lock(msg->drone_read);
  if(!msg->video_stream_on){
    bool flag=tello->enable_video_stream();
    if(flag){
      msg->video_stream_on=true;
      std::cout<<"Video Stream Enabled On Drone"<<std::endl;
    }
  }
}

void drone::transmit(message* msg){

  while(true){
    if(msg->connected){

      if(msg->command_TakeOFF){
        takeoff();
        msg->command_TakeOFF=false;
      }

      if(msg->command_Land){
        land();
        msg->command_Land=false;
      }

      if(msg->command_Up){
        up(drone_min_input);
        msg->command_Up=false;
      }

      if(msg->command_Down){
        dwn(drone_min_input);
        msg->command_Down=false;
      }

      if(abs(msg->jstk.axis0_Nvalue)>input_th){
        if(msg->jstk.axis0_Nvalue<0){
          double value=-drone_min_input+max_distance_step*(msg->jstk.axis0_Nvalue-input_th);
          left(-value);
        }else{
          double value=drone_min_input+max_distance_step*(msg->jstk.axis0_Nvalue-input_th);
          right(value);
        }
      }

      if(abs(msg->jstk.axis1_Nvalue)>input_th){
        if(msg->jstk.axis1_Nvalue<0){
          double value=-drone_min_input+max_distance_step*(msg->jstk.axis1_Nvalue-input_th);
          fwd(-value);
        }else{
          double value=drone_min_input+max_distance_step*(msg->jstk.axis1_Nvalue-input_th);
          bwd(value);
        }
      }

      if(msg->jstk.axis2_Nvalue!=0){
        rotate(msg->jstk.axis2_Nvalue*max_angle_step);
      }

      if(msg->command_Stop){
        stop();
        msg->command_Stop=false;
      }

    }
  }
}

void drone::stream(message* msg, i3DEDGE_GUI* caller){

  tello=new Tello();
  const char* const TELLO_STREAM_URL{"udp://0.0.0.0:11111"};
  cv::VideoCapture capture; //{TELLO_STREAM_URL, cv::CAP_FFMPEG};
  bool cap_opened=false;

  while(true){

    if(msg->Connect_EN){
      if(!msg->connected){
        connect(msg);
      }
      msg->Connect_EN=false;
    }

    if(msg->connected){
      if(msg->video_stream_EN){
         if(!msg->video_stream_on){
          stream_on(msg);
          msg->video_stream_on=true;
        }
      }
    }

    if(msg->video_stream_on){
      if(!cap_opened){
        if(capture.open(TELLO_STREAM_URL, cv::CAP_FFMPEG)){
          std::cout<<"Capture open"<<std::endl;
          cap_opened=true;
        }else{
        }
      }
    }

    if(cap_opened){

      cv::Mat image;
      capture >> image;
      if(!image.empty()){
          msg->good_frame=true;
      }else{
        msg->good_frame=false;
      }

      if(msg->good_frame){

        {std::lock_guard<std::mutex> lock(msg->drone_read);
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        msg->cam_image=image.clone();}

        if(msg->video_stream_EN){
          caller->connectfromdrone(msg);

        }
      }
    }
  }
}
