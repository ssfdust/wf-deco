#include <iostream>
#include <gtkmm/icontheme.h>
#include <gtkmm/main.h>
#include <glibmm.h>
#include <gdk/gdkcairo.h>

int main(int argc, char * argv[]){
    std::string icon_name = "firefox";
    auto _GTKMain = new Gtk::Main(0, 0, false);
    return 0;
}
