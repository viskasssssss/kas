#pragma once

#include "kpch.hh"

#include "Kas/Core/Defines.hh"
#include "Kas/Event/Event.hh"

namespace kas {
    struct WindowProps {
        std::string title;
        unsigned int width;
        unsigned int height;

        WindowProps(const std::string& title = "kas Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : title(title), width(width), height(height) {}
    };

    class KAS_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void on_update() = 0;

        virtual unsigned int get_width() const = 0;
        virtual unsigned int get_height() const = 0;

        virtual void set_event_callback(const EventCallbackFn& callback) = 0;

        static Scope<Window> create(const WindowProps& props = WindowProps());
    };
}
