#pragma once

#ifdef _WIN32

extern kas::Application* kas::CreateApplication();

int main() {
    kas::Log::init();
    KAS_INFO("Initialized logging");

    kas::Application* app = kas::CreateApplication();
    app->run();
    delete app;
}

#endif
