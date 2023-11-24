#include "axis_widget.h"

axis_widget::axis_widget(int w, int h){
  set_size_request(w,h);
  set_position(0);
}

bool axis_widget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){

  double p = 1.0 - (pos + 1.0) / 2.0;

  int w  = get_allocation().get_width()-10;
  int h  = get_allocation().get_height()-10;

  cr->translate(5, 5);

  // Outer Rectangle
  cr->set_source_rgb(0.0, 0.0, 0.0);
  cr->set_line_width(1.0);
  cr->rectangle(0, 0, w, h);
  cr->stroke();

  int dh = h*p;
  cr->rectangle(0, h - dh, w, dh);
  cr->fill();

  return true;

}

void axis_widget::set_position(double p){
  pos = p;
  queue_draw();
}
