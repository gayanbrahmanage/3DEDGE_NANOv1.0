#ifndef rotate_widget_H
#define rotate_widget_H

#include <gtkmm/drawingarea.h>
#include <gtkmm/alignment.h>
#include <math.h>

class rotate_widget : public Gtk::Alignment{

private:
  double pos;

public:
  rotate_widget(int width, int height);
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& context) override;
  void update(double p);

};

#endif
