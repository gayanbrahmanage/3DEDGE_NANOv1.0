#ifndef throttle_widget_H
#define throttle_widget_H

#include <gtkmm/drawingarea.h>
#include <gtkmm/alignment.h>

class throttle_widget : public Gtk::Alignment{

private:
  double alt;

public:
  throttle_widget(int width, int height);
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& context) override;
  void update(double alt);

};

#endif
