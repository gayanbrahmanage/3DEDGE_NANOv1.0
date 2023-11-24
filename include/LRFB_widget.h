
#ifndef LRFB_widget_H
#define LRFB_widget_H

#include <gtkmm/drawingarea.h>
#include <gtkmm/alignment.h>

class LRFB_widget : public Gtk::Alignment{

private:
  double posL,posR,posF,posB;

public:
  LRFB_widget(int width, int height);
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& context) override;
  void update(double l, double r, double f,double b);

};

#endif
