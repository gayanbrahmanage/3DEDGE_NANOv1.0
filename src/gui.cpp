#include "gui.h"
//CopyRight! Autonomous Systems and Intelligent Sensing Laboratory    video_image("../extra/camera.png")

i3DEDGE_GUI::i3DEDGE_GUI():
    frame_control("Control"),
    frame_input(),
    frame_inputL("Input"),
    frame_move("Move"),
    frame_smove("Step Move"),
    frame_rotate("Yaw"),
    frame_funnctions("Functions"),
    frame_Video("Camera"),
    frame_status("Status"),
    frame_connected("Connection"),
    frame_connect("Connect"),
    frame_throttle("Alt"),

    boxMain(Gtk::ORIENTATION_VERTICAL,5), // Main
    boxTop(Gtk::ORIENTATION_VERTICAL), //Top
    boxTopH(Gtk::ORIENTATION_HORIZONTAL), //Top horizontal

    boxMiddle(Gtk::ORIENTATION_HORIZONTAL), //Middle
    boxMiddleL(Gtk::ORIENTATION_VERTICAL), //Midlle Left
    boxMiddleLL(Gtk::ORIENTATION_HORIZONTAL),
    boxMove(Gtk::ORIENTATION_VERTICAL),
    boxSMove(Gtk::ORIENTATION_VERTICAL),
    boxRotate(Gtk::ORIENTATION_VERTICAL),

    boxMiddleM(Gtk::ORIENTATION_VERTICAL), //Midlle Left
    boxVideo(Gtk::ORIENTATION_VERTICAL),
    boxThrottle(Gtk::ORIENTATION_VERTICAL),

    boxMiddleR(Gtk::ORIENTATION_VERTICAL), //Midlle right
    boxMiddleRM(Gtk::ORIENTATION_VERTICAL),
    boxConnection(Gtk::ORIENTATION_HORIZONTAL),
    boxMiddleRButtons(Gtk::ORIENTATION_HORIZONTAL),

    boxBottom(Gtk::ORIENTATION_VERTICAL),
    boxFunctions(Gtk::ORIENTATION_HORIZONTAL),

    sbtn_manual(100,50, sbtn_manual_name, 0.2,0.2,0.2),
    sbtn_ready(100,50,sbtn_ready_name, 0.2,0.2,0.2),

    sbtn_Takeoff(100,50,sbtn_Takeoff_name, 0.2,0.2,0.2),
    sbtn_Land(100,50,sbtn_Land_name, 0.2,0.2,0.2),
    sbtn_flip(100,50,sbtn_flip_name, 0.2,0.2,0.2),
    sbtn_up(100,50,sbtn_Up_name, 0.2,0.2,0.2),
    sbtn_dwn(100,50,sbtn_Dwn_name, 0.2,0.2,0.2),

    sbtn_stop(100,50,sbtn_stop_name, 0.2,0.2,0.2),
    sbtn_jstic_connected(80,50,sbtn_jstic_name, 0.0,0.6,0.0),
    sbtn_video_connected(80,50,sbtn_video_name, 0.0,0.0,0.6),
    sbtn_drone_connected(80,50,sbtn_drone_name, 0.6,0.0,0.0),

    sbtn_AIdepthON(100,50,sbtn_AIdepth_name, 0.6,0.0,0.0),
    sbtn_DetectorON(100,50,sbtn_Detector_name, 0.6,0.0,0.0),

    drone_connect_button("Connect Drone"),
    video_on("Stream"),

    lrfb(150,150),
    lrfbs(150,150),
    rot(150,75),
    th(30,720),
    video_image("../extra/camera.png")
    {   // creates a new button with label "Hello World".

        // Sets the border width of the window.
        set_title("3D-EDGE");
        //set_default_size(1260, 820);
        boxMain.set_border_width(10);
        add(boxMain);

        boxMain.pack_start(frame_control);
        boxTop.set_border_width(5);
        frame_control.add(boxTop);
        boxTop.pack_start(boxTopH, FALSE, FALSE, 0);
        boxTopH.pack_start(sbtn_manual, FALSE, FALSE, 0);
        boxTopH.pack_start(sbtn_ready, FALSE, FALSE, 0);

        boxMain.pack_start(frame_input);
        boxMiddleLL.set_border_width(5);
        frame_input.add(boxMiddleLL);

        boxMiddleLL.pack_start(frame_inputL, FALSE, FALSE, 0);
        boxMiddleL.set_border_width(5);
        frame_inputL.add(boxMiddleL);
        boxMiddleL.pack_start(sbtn_Takeoff, FALSE, FALSE, 0);
        boxMiddleL.pack_start(sbtn_Land, FALSE, FALSE, 0);
        boxMiddleL.pack_start(sbtn_up, FALSE, FALSE, 0);
        boxMiddleL.pack_start(sbtn_dwn, FALSE, FALSE, 0);


        boxMiddleL.pack_start(frame_move, FALSE, FALSE, 0);
        boxMove.set_border_width(5);
        frame_move.add(boxMove);
        boxMove.pack_start(lrfb, FALSE, FALSE, 0);
        boxMiddleL.pack_start(frame_rotate, FALSE, FALSE, 0);
        boxRotate.set_border_width(5);
        frame_rotate.add(boxRotate);
        boxRotate.pack_start(rot, FALSE, FALSE, 0);
        boxMiddleL.pack_start(frame_smove, FALSE, FALSE, 0);
        boxSMove.set_border_width(5);
        frame_smove.add(boxSMove);
        boxSMove.pack_start(lrfbs, FALSE, FALSE, 0);

        boxMiddleL.pack_start(sbtn_flip, FALSE, FALSE, 0);
        boxMiddleL.pack_start(sbtn_stop, FALSE, FALSE, 0);


        boxMiddleM.set_border_width(5);
        boxMiddleLL.pack_start(boxMiddleM, FALSE, FALSE, 0);
        boxMiddleM.pack_start(frame_Video, FALSE, FALSE, 0);
        boxVideo.set_border_width(5);
        frame_Video.add(boxVideo);
        boxVideo.pack_start(video_image, Gtk::PACK_SHRINK);

        boxMiddleLL.pack_start(frame_throttle, FALSE, FALSE, 0);
        boxThrottle.set_border_width(5);
        frame_throttle.add(boxThrottle);
        boxThrottle.pack_start(th, FALSE, FALSE, 0);

        boxMiddleLL.pack_start(boxMiddleR, FALSE, FALSE, 0);
        boxMiddleR.pack_start(frame_status, FALSE, FALSE, 0);
        boxMiddleRM.set_border_width(5);
        frame_status.add(boxMiddleRM);
        boxMiddleRM.pack_start(frame_connected, FALSE, FALSE, 0);
        frame_connected.add(boxConnection);
        boxConnection.pack_start(sbtn_jstic_connected,FALSE, FALSE, 0);
        boxConnection.pack_start(sbtn_video_connected,FALSE, FALSE, 0);
        boxConnection.pack_start(sbtn_drone_connected,FALSE, FALSE, 0);

        boxMiddleRM.pack_start(frame_connect, FALSE, FALSE, 0);
        boxMiddleRButtons.set_border_width(5);
        frame_connect.add(boxMiddleRButtons);
        boxMiddleRButtons.pack_start(drone_connect_button, FALSE, FALSE, 0);
        boxMiddleRButtons.pack_start(seperator1);
        boxMiddleRButtons.pack_start(video_on);

        boxMain.pack_start(frame_funnctions);
        boxFunctions.set_border_width(5);
        frame_funnctions.add(boxFunctions);
        boxFunctions.pack_start(sbtn_AIdepthON,FALSE, FALSE, 0);
        boxFunctions.pack_start(sbtn_DetectorON,FALSE, FALSE, 0);

        Dispatcher_joy.connect(sigc::mem_fun(*this, &i3DEDGE_GUI::on_notification_from_worker_thread));
        Dispatcher_drone.connect(sigc::mem_fun(*this, &i3DEDGE_GUI::on_notification_from_worker_thread_drone));

        drone_connect_button.signal_clicked().connect(sigc::mem_fun(*this, &i3DEDGE_GUI::on_drone_connect_button_clicked));
        video_on.signal_clicked().connect(sigc::mem_fun(*this, &i3DEDGE_GUI::on_video_on_button_clicked));

        show_all_children();

}

i3DEDGE_GUI::~i3DEDGE_GUI(){

}

void i3DEDGE_GUI::init(message* msg_){
  msg=msg_;
}

void i3DEDGE_GUI::on_video_on_button_clicked(){

  if(!msg->video_stream_EN){
      msg->video_stream_EN=true;
      std::cout<<"Video Stream Enabled"<<std::endl;
  }else{
      msg->video_stream_EN=false;
  }

}

void i3DEDGE_GUI::on_drone_connect_button_clicked(){
  std::cout<<"Connecting to drone..."<<std::endl;
  std::lock_guard<std::mutex> lock(msg->drone_read);
  msg->Connect_EN=true;
}

void i3DEDGE_GUI::connect(message* msg_){
  Dispatcher_joy.emit();
  std::lock_guard<std::mutex> lock(msg_->jstick_read);
  msg=msg_;
  //std::cout<<msg->jstk.button0<<std::endl;
}

void i3DEDGE_GUI::connectfromdrone(message* msg_){
  Dispatcher_drone.emit();
  std::lock_guard<std::mutex> lock(msg_->drone_read);
  msg=msg_;

}


void i3DEDGE_GUI::on_notification_from_worker_thread_drone(){
  update_widgets_drone();
}

void i3DEDGE_GUI::update_widgets_drone(){
  std::lock_guard<std::mutex> lock(msg->drone_read);
  video_image.update(msg->cam_image);
  //std::cout<<"Frame update received"<<std::endl;
}

void i3DEDGE_GUI::on_notification_from_worker_thread(){
  update_widgets();
}

void i3DEDGE_GUI::update_widgets(){

  std::lock_guard<std::mutex> lock(msg->jstick_read);

  // if(msg->jstk.button4){
  //   if(!msg->video_stream_EN)
  //       msg->video_stream_EN=true;
  //   else msg->video_stream_EN=false;
  // }

  std::string name="Input";
  status=!status;
  if(msg->joystick_connected){
    sbtn_jstic_connected.update(status, name,0.5,0.2,0.8);
  }else{
    sbtn_jstic_connected.update(false, name,0.2,0.2,0.2);
  }

  name="Manual";
  if(msg->jstk.button0){
    name="Auto";
    sbtn_manual.update(true, name,0.8,0.0,0.0);
  }else{
    sbtn_manual.update(true, name,0.0,0.8,0.0);
  }

  name="Flip";
  if(msg->jstk.button1){
    sbtn_flip.update(true, name,0.8,0.1,0.6);
  }else{
    sbtn_flip.update(false, name,0.2,0.2,0.2);
  }

  name="Up";
  if(msg->jstk.button2){
    sbtn_up.update(true, name,0.8,0.0,0.0);
    msg->command_Up=true;
  }else{
    sbtn_up.update(false, name,0.2,0.2,0.2);
  }

  name="Down";
  if(msg->jstk.button3){
    sbtn_dwn.update(true, name,0.0,0.8,0.0);
    msg->command_Down=true;
  }else{
    sbtn_dwn.update(false, name,0.2,0.2,0.2);
  }

  name="TakeOff";
  if(msg->jstk.button4){
    sbtn_Takeoff.update(true, name,1.0,0.6,0.0);
    msg->command_TakeOFF=true;
  }else{
    sbtn_Takeoff.update(false, name,0.2,0.2,0.2);
  }

  name="Land";
  if(msg->jstk.button5){
    sbtn_Land.update(true, name,0.7,0.3,0.1);
    msg->command_Land=true;
  }else{
    sbtn_Land.update(false, name,0.2,0.2,0.2);
  }

  name="Stop";
  if(msg->jstk.button11){
    sbtn_stop.update(true, name,1.0,0.0,0.0);
    msg->command_Stop=true;
  }else{
    sbtn_stop.update(false, name,0.2,0.2,0.2);
  }

  double value=msg->jstk.axis0_value-msg->jstk.axis0calib.mid;
  value/=msg->jstk.axis0calib.max;
  double l=0,r=0,f=0,b=0;

  if(value>0){
    r=value;
  }else if(value<0){
    l=-value;
  }
  msg->jstk.axis0_Nvalue=value;

  value=msg->jstk.axis1_value-msg->jstk.axis1calib.mid;
  value/=msg->jstk.axis1calib.max;

  if(value>0){
    b=value;
  }else if(value<0){
    f=-value;
  }

  msg->jstk.axis1_Nvalue=value;
  lrfb.update(l,r,f,b);


  value=msg->jstk.axis2_value-msg->jstk.axis2calib.mid;
  value/=msg->jstk.axis2calib.max;
  msg->jstk.axis2_Nvalue=value;
  rot.update(value);

  value=msg->jstk.axis3_value-msg->jstk.axis3calib.min;
  value/=(msg->jstk.axis3calib.max-msg->jstk.axis3calib.min);
  value=1.0-value;
  msg->jstk.axis3_Nvalue=value;
  //std::cout<< msg->jstk.axis3_Nvalue<<std::endl;
  th.update(value);


  value=msg->jstk.axis4_value-msg->jstk.axis4calib.mid;
  value/=msg->jstk.axis4calib.max;
  l=0,r=0,f=0,b=0;

  if(value>0){
    r=value;
  }else if(value<0){
    l=-value;
  }
  msg->jstk.axis4_Nvalue=value;

  value=msg->jstk.axis5_value-msg->jstk.axis5calib.mid;
  value/=msg->jstk.axis5calib.max;

  if(value>0){
    b=value;
  }else if(value<0){
    f=-value;
  }
  msg->jstk.axis5_Nvalue=value;
  lrfbs.update(l,r,f,b);

  name="Idle";
  if(msg->joystick_connected && msg->connected && msg->video_stream_on){
    name="Ready";
    sbtn_ready.update(true, name,0.0,0.8,0.0);
  }else{
    sbtn_ready.update(true, name,0.8,0.8,0.0);
  }

  name="Video";
  if(msg->video_stream_on){
    sbtn_video_connected.update(true, name,0.8,0.0,0.0);
  }else{
    sbtn_video_connected.update(false, name,0.2,0.2,0.2);
  }

  name="UAV";
  if(msg->connected){
    sbtn_drone_connected.update(true, name,0.8,0.0,0.4);
  }else{
    sbtn_drone_connected.update(false, name,0.2,0.2,0.2);
  }

  name="AI-Depth";
  if(msg->AIdepthOn){
    sbtn_AIdepthON.update(true, name,0.0,1.0,0.7);
  }else{
    sbtn_AIdepthON.update(false, name,0.2,0.2,0.2);
  }

  name="Detector";
  if(msg->DetectorON){
    sbtn_DetectorON.update(true, name,0.8,0.0,0.1);
  }else{
    sbtn_DetectorON.update(false, name,0.2,0.2,0.2);
  }

}
