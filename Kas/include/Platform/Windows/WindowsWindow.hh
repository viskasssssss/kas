#pragma once

#ifdef _WIN32

#include "Kas/OS/Window.hh"

#include <Windows.h>

namespace kas {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void on_update() override;

        inline unsigned int get_width() const override { return m_data.width; }
        inline unsigned int get_height() const override { return m_data.height; }

        inline void set_event_callback(const EventCallbackFn& callback) override { m_data.event_callback = callback; }
    private:
        virtual void init(const WindowProps& props);
        virtual void shutdown();

        static LRESULT CALLBACK WindowsWindow::window_proc(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param);
    private:
        HWND m_hwnd;

        struct WindowData {
            std::string title;
            unsigned int width, height;
            bool vsync;

            EventCallbackFn event_callback;
        };

        WindowData m_data;
    };
}

#endif
