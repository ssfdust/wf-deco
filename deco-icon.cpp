#include <giomm/desktopappinfo.h>
#include <gtkmm/button.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/icontheme.h>
#include <gtkmm/image.h>

#include <gdkmm/display.h>
#include <gdkmm/seat.h>
#include <iostream>
#include "deco-icon.hpp"
#include "gtk-utils.hpp"

namespace IconProvider
{
    using Icon = Glib::RefPtr<Gio::Icon>;

    /* Gio::DesktopAppInfo
     *
     * Usually knowing the app_id, we can get a desktop app info from Gio
     * The filename is either the app_id + ".desktop" or lower_app_id + ".desktop" */
    Icon get_from_desktop_app_info(std::string app_id)
    {
        Glib::RefPtr<Gio::DesktopAppInfo> app_info;

        std::vector<std::string> prefixes = {
            "",
            "/usr/share/applications/",
            "/usr/share/applications/kde/",
            "/usr/share/applications/org.kde.",
            "/usr/local/share/applications/",
            "/usr/local/share/applications/org.kde.",
        };

        std::vector<std::string> app_id_variations = {
            app_id,
            tolower(app_id),
        };

        std::vector<std::string> suffixes = {
            "",
            ".desktop"
        };

        for (auto& prefix : prefixes)
        {
            for (auto& id : app_id_variations)
            {
                for (auto& suffix : suffixes)
                {
                    if (!app_info)
                    {
                        app_info = Gio::DesktopAppInfo
                            ::create_from_filename(prefix + id + suffix);
                    }
                }
            }
        }

        if (app_info) // success
            return app_info->get_icon();

        return Icon{};
    }

    std::string get_icon_path(std::string app_id)
    {
        /* try to load the DesktopAppInfo */
        auto icon = get_from_desktop_app_info(app_id);
        std::string icon_name = "unknown";
        auto icon_theme = Gtk::IconTheme::get_default();
        auto icon_info = icon_theme->lookup_icon(icon_name, 24);
        if (!icon_info)
        {
            std::cerr << "Failed to load icon \"" << icon_name << "\"" << std::endl;
            return ;
        }
        return icon_info.get_filename();

        if (!icon)
        {
            /* Finally try directly looking up the icon, if it exists */
            if (Gtk::IconTheme::get_default()->lookup_icon(app_id, 24))
                icon_name = app_id;
        } else
        {
            icon_name = icon->to_string();
        }

        WfIconLoadOptions options;
        options.user_scale = scale;
        get_image_icon(image, icon_name, size, options);

        /* finally found some icon */
        if (icon_name != "unknown")
        {
            found_icon = true;
            break;
        }
    }
};
