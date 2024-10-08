#ifndef status_button_H
#define status_button_H

#include <gtkmm/drawingarea.h>


class status_button : public Gtk::DrawingArea{

  public:
    std::string name=" Default ";
    bool status=false;
    double r =0.1;
    double g =0.1;
    double b =0.1;

    status_button(int, int, std::string&,double r, double g, double b);
    ~status_button();
    void update(bool t, std::string& name_, double r, double g, double b);

  protected:

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

};

#endif
