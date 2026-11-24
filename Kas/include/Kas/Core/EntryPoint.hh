#pragma once

#ifdef _WIN32

extern kas::Application* kas::CreateApplication();

int main() {
    kas::Application* app = kas::CreateApplication();
    app->run();
    delete app;
}

#endif