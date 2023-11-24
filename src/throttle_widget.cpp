#include "throttle_widget.h"

throttle_widget::throttle_widget(int w, int h){
  set_size_request(w,h);
  update(0.0);
}

bool throttle_widget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){


  int w  = get_allocation().get_width()-10;
  int h  = get_allocation().get_height()-10;

  cr->translate(5, 5);

  // Outer Rectangle
  cr->set_source_rgba(0.0, 0.0, 0.0, 0.1);
  cr->set_line_width(1.0);
  cr->rectangle(0, 0, w, h);
  cr->fill();
  cr->stroke();

  cr->set_source_rgb(0.8, 0.4, 0.0);
  cr->set_line_width(1.0);
  cr->rectangle(0, h-h*alt, w, h*alt);
  cr->fill();
  cr->stroke();

  return true;

}

void throttle_widget::update(double alt_){
  alt = alt_;
  queue_draw();
}
