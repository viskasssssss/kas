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

    void Application::on_event(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(KAS_BIND_EVENT_FN(Application::on_window_close));

        KAS_CORE_INFO(e);
    }

    bool Application::on_window_close(WindowCloseEvent& e) {
        m_running = false;

        return true;
    }

    void Application::run() {
        while (m_running) {
            m_window->on_update();
        }
    }
}
