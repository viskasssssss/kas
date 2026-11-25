#pragma once

#include "Kas/Core/Defines.hh"
#include "Kas/Event/Event.hh"
#include "Kas/Event/ApplicationEvent.hh"
#include "Kas/OS/Window.hh"

namespace kas {
    class KAS_API Application {
    public:
        Application();
        virtual ~Application();

        void run();

        void on_event(Event& e);
    private:
        bool on_window_close(WindowCloseEvent& e);
    private:
        Scope<Window> m_window;
        bool m_running = true;
    };

    Application* CreateApplication();
}
