#pragma once

#ifdef _WIN32

extern kas::Application* kas::CreateApplication();

int main() {
    kas::Log::init();
    KAS_CORE_WARN("Test!");
    KAS_ERROR("Test! {0}", 5);

    kas::Application* app = kas::CreateApplication();
    app->run();
    delete app;
}

#endif
