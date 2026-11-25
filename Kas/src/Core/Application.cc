#include "kpch.hh"

#include "Kas/Core/Application.hh"

#include "Kas/Core/Log.hh"

namespace kas {
    Application::Application() {
        m_window = Window::create();
        m_window->set_event_callback(KAS_BIND_EVENT_FN(Application::on_event));
    }

    Application::~Application() {

    }

    void Application::push_layer(Layer* layer) {
        m_layer_stack.push_layer(layer);
    }

    void Application::push_overlay(Layer* overlay) {
        m_layer_stack.push_overlay(overlay);
    }

    void Application::on_event(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(KAS_BIND_EVENT_FN(Application::on_window_close));

        for (auto it = m_layer_stack.end(); it != m_layer_stack.begin(); ) {
            (*--it)->on_event(e);
            if (e.handled)
                break;
        }
    }

    bool Application::on_window_close(WindowCloseEvent& e) {
        m_running = false;

        return true;
    }

    void Application::run() {
        while (m_running) {
            for (Layer* layer : m_layer_stack)
                layer->on_update();

            m_window->on_update();
        }
    }
}
