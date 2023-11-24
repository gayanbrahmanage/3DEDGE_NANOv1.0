#ifndef i3DEDGE_H
#define i3DEDGE_H

#include "parameters.h"
#include "message.h"
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <gtkmm/application.h>
#include "video_widget.h"
#include "status_button.h"
#include "axis_widget.h"
#include "LRFB_widget.h"
#include "rotate_widget.h"
#include "throttle_widget.h"

#include <thread>

class i3DEDGE_GUI: public Gtk::Window{
  private:
    // Dispatcher handler.
    parameters* param=new parameters();
    bool status=false;
    void on_notification_from_worker_thread();
    void on_notification_from_worker_thread_drone();

  public:

    Glib::Dispatcher Dispatcher_joy;
    Glib::Dispatcher Dispatcher_drone;

    message* msg=new message;
    void init(message*);
    void connect(message*);
    void connectfromdrone(message*);

    i3DEDGE_GUI();
    virtual ~i3DEDGE_GUI();

  protected:
    //Signal handlers:
    void on_button_clicked();
    void update_widgets();
    void update_widgets_drone();
    void on_drone_connect_button_clicked();
    void on_video_on_button_clicked();


    //Member widgets:
    Gtk::Box boxMain;
    Gtk::Box boxTop,boxTopH;
    Gtk::Box boxMiddle, boxMiddleL,boxMiddleLL, boxMiddleM,boxMiddleR;
    Gtk::Box boxBottom;
    Gtk::Box boxVideo;
    Gtk::VSeparator seperator1, seperator2;
    Gtk::Frame frame_control, frame_input,frame_funnctions,frame_status;
    Gtk::Frame frame_inputL;
    Gtk::Frame frame_Video;

    Gtk::Frame frame_throttle;
    Gtk::Box boxThrottle;

    Gtk::Frame frame_move;
    Gtk::Box boxMove;

    Gtk::Frame frame_smove;
    Gtk::Box boxSMove;

    Gtk::Frame frame_connected;
    Gtk::Box boxConnection;

    Gtk::Frame frame_connect;
    Gtk::Box boxMiddleRButtons;

    Gtk::Frame frame_rotate;
    Gtk::Box boxRotate;

    Gtk::Box boxMiddleRM;
    Gtk::Box boxFunctions;

    Gtk::Button drone_connect_button;
    Gtk::Button video_on;

    std::string sbtn_manual_name="Manual";
    std::string sbtn_ready_name="Idle";
    std::string sbtn_Takeoff_name="TakeOff";
    std::string sbtn_Land_name="Land";
    std::string sbtn_flip_name="Flip";
    std::string sbtn_Up_name="Up";
    std::string sbtn_Dwn_name="Down";
    std::string sbtn_stop_name="Stop";
    std::string sbtn_jstic_name="Input";
    std::string sbtn_video_name="Video";
    std::string sbtn_drone_name="Drone";
    std::string sbtn_AIdepth_name="AI-Depth";
    std::string sbtn_Detector_name="Detector";

    // video_widget video_image;
    status_button sbtn_manual;
    status_button sbtn_ready;

    status_button sbtn_Takeoff;
    status_button sbtn_Land;
    status_button sbtn_flip;
    status_button sbtn_up;
    status_button  sbtn_dwn;

    status_button sbtn_stop;

    status_button sbtn_jstic_connected;
    status_button sbtn_video_connected;
    status_button sbtn_drone_connected;

    status_button sbtn_AIdepthON;
    status_button sbtn_DetectorON;

    throttle_widget th;

    LRFB_widget lrfb;
    LRFB_widget lrfbs;

    rotate_widget rot;


    video_widget video_image;

};

#endif
