#include <gtk-utils.hpp>
#include <glibmm.h>
#include <gtkmm/icontheme.h>
#include <gdk/gdkcairo.h>
#include <iostream>

std::string get_image_icon(std::string icon_name)
{
    auto icon_theme = Gtk::IconTheme::get_default();
    auto icon_info = icon_theme->lookup_icon(icon_name, scaled_size);

    if (!icon_info)
    {
        std::cerr << "Failed to load icon \"" << icon_name << "\"" << std::endl;
        return;
    }

    if (options.invert)
        invert_pixbuf(pbuff);

    set_image_pixbuf(image, pbuff, scale);
}
