#include "status_button.h"

status_button::status_button(int w, int h,std::string& name, double r, double g, double b){

  set_size_request(w,h);

}

status_button::~status_button(){

}

bool status_button::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){

  Gtk::DrawingArea::on_draw(cr);
  int w  = get_allocation().get_width()  - 10;
  int h  = get_allocation().get_height() - 10;

  cr->set_source_rgb(r, g, b);
  cr->set_line_width(1.0);
  cr->translate(5, 5);
  cr->rectangle(0, 0, w, h);

  if (status)
    cr->fill_preserve();

  cr->stroke();

  if (status)
    cr->set_source_rgb(1.0, 1.0, 1.0);

  cr->set_font_size(13);
  // FIXME: There are better ways to center text

  cr->move_to(w/2-20, h/2+3);
  cr->show_text(name);

  return true;
}


void status_button::update(bool t, std::string& name_, double r_, double g_, double b_){
  name=name_;
  status=t;
  r=r_;
  g=g_;
  b=b_;
  queue_draw();
}

