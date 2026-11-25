#pragma once

#include "Kas/Core/Defines.hh"

#include "Kas/OS/Window.hh"
#include "Kas/Layer/LayerStack.hh"
#include "Kas/Event/Event.hh"
#include "Kas/Event/ApplicationEvent.hh"

namespace kas {
    class KAS_API Application {
    public:
        Application();
        virtual ~Application();

        void run();

        void on_event(Event& e);

        void push_layer(Layer* layer);
        void push_overlay(Layer* overlay);
    private:
        bool on_window_close(WindowCloseEvent& e);
    private:
        Scope<Window> m_window;
        bool m_running = true;
        LayerStack m_layer_stack;
    };

    Application* CreateApplication();
}
