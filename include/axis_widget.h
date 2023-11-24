
#ifndef axis_widget_H
#define axis_widget_H

#include <gtkmm/drawingarea.h>
#include <gtkmm/alignment.h>

class axis_widget : public Gtk::Alignment{

private:
  double pos;

public:
  axis_widget(int width, int height);
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& context) override;
  void set_position(double p);

};

#endif
