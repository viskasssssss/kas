#include "Kas/Core/Application.hh"

#include "Kas/Event/ApplicationEvent.hh"
#include "Kas/Core/Log.hh"

namespace kas {
    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::run() {
        WindowResizeEvent e(1280, 720);
        if (e.is_in_category(EventCategoryApplication)) {
            KAS_INFO(e);
        }
        if (e.is_in_category(EventCategoryInput)) {
            KAS_INFO(e);
        }

        while (true);
    }
}
