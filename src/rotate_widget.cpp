#include "rotate_widget.h"

rotate_widget::rotate_widget(int w, int h){
  set_size_request(w,h);
  update(0.0);
}

bool rotate_widget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){

  // double p = 1.0 - (pos + 1.0) / 2.0;

  int w  = get_allocation().get_width()-10;
  int h  = get_allocation().get_height()-10;

  cr->translate(5, 5);

  // Outer Rectangle
  cr->set_source_rgb(0.0, 0.0, 0.0);
  cr->set_line_width(1.0);
  cr->rectangle(0, 0, w, h);
  cr->stroke();

  cr->arc(w/2, w/2, w/2, -M_PI, 0);
  cr->set_source_rgba(0.0, 0.0, 0.0, 0.1);
  cr->fill();

  cr->set_line_width(3.0);
  cr->set_source_rgb(0.6, 0.6, 0.6);
  cr->move_to(w/2,h);
  cr->line_to(w/2, 0);
  cr->stroke();

  double angle=M_PI/2*pos;
  double xc=w/2*sin(angle);
  double yc=w/2*cos(angle);

  cr->set_line_width(3.0);
  cr->set_source_rgb(0.9, 0.0, 0.0);
  cr->move_to(w/2,h);
  cr->line_to(w/2+xc, w/2-yc);
  cr->stroke();


  cr->set_line_width(3.0);
  cr->set_source_rgb(0.4, 0.0, 0.0);
  cr->arc(w/2+xc, w/2-yc, w/16, 0, 2*M_PI);
  cr->fill();
  cr->stroke();


  return true;

}

void rotate_widget::update(double p /* -1 to +1*/){
  pos = p;
  queue_draw();
}
