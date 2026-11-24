#pragma once

#include "Kas/Core/Defines.hh"

namespace kas {
    class KAS_API Application {
    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application* CreateApplication();
}
