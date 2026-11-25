#include "kpch.hh"

#ifdef _WIN32

#include "Platform/Windows/WindowsWindow.hh"
#include "Platform/Windows/WindowsSys.hh"

#include "Kas/Input/KeyCode.hh"
#include "Kas/Event/ApplicationEvent.hh"
#include "Kas/Event/KeyEvent.hh"
#include "Kas/Event/MouseEvent.hh"

#include <Windowsx.h>

namespace kas {
    LRESULT CALLBACK WindowsWindow::window_proc(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param) {
        if (u_msg == WM_NCCREATE) {
            auto* cs = reinterpret_cast<CREATESTRUCTW*>(l_param);
            SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(cs->lpCreateParams));
            return DefWindowProcW(hwnd, u_msg, w_param, l_param);
        }

        WindowData* data = kas::win32::get_window_user_data<WindowData>(hwnd);
        // make sure data is initialized!
        if (!data || !data->event_callback) {
            return DefWindowProcW(hwnd, u_msg, w_param, l_param);
        }

        switch (u_msg) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN: {
                KeyCode key = kas::win32::win32_to_native_key_code(w_param, l_param);
                if (key != 0) {
                    bool isRepeat = (l_param & (1 << 30)) != 0;

                    if (isRepeat) {
                        uint16_t repeatCount = LOWORD(l_param);
                        KeyPressedEvent event(key, repeatCount);
                        data->event_callback(event);
                    } else {
                        KeyPressedEvent event(key, 0);
                        data->event_callback(event);
                    }
                }

                if (u_msg == WM_SYSKEYDOWN && w_param == VK_F4)
                    return DefWindowProcW(hwnd, u_msg, w_param, l_param);
                
                return 0;
            }
            case WM_KEYUP:
            case WM_SYSKEYUP: {
                KeyCode key = kas::win32::win32_to_native_key_code(w_param, l_param);
                if (key != 0) {
                    KeyReleasedEvent event(key);
                    data->event_callback(event);
                }
                
                return 0;
            }
            case WM_LBUTTONDOWN:
            case WM_RBUTTONDOWN:
            case WM_MBUTTONDOWN:
            case WM_XBUTTONDOWN:
            {
                kas::MouseCode button = kas::win32::win32_to_native_mouse_code(u_msg, w_param);
                if (button != static_cast<kas::MouseCode>(-1))
                {
                    SetCapture(hwnd);

                    MouseButtonPressedEvent event(button);
                    data->event_callback(event);
                }

                return (u_msg == WM_XBUTTONDOWN) ? TRUE : 0;
            }
            case WM_LBUTTONUP:
            case WM_RBUTTONUP:
            case WM_MBUTTONUP:
            case WM_XBUTTONUP:
            {
                kas::MouseCode button = kas::win32::win32_to_native_mouse_code(u_msg, w_param);
                if (button != static_cast<kas::MouseCode>(-1))
                {
                    if ((w_param & (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON | MK_XBUTTON1 | MK_XBUTTON2)) == 0)
                        ReleaseCapture();

                    MouseButtonReleasedEvent event(button);
                    data->event_callback(event);
                }

                return (u_msg == WM_XBUTTONUP) ? TRUE : 0;
            }
            case WM_MOUSEWHEEL:
            {
                float y_offset = static_cast<float>(GET_WHEEL_DELTA_WPARAM(w_param)) / static_cast<float>(WHEEL_DELTA);
                float x_offset = 0.0f;

                MouseScrolledEvent event(x_offset, y_offset);
                data->event_callback(event);

                return 0;
            }
            case WM_MOUSEHWHEEL:
            {
                float x_offset = -static_cast<float>(GET_WHEEL_DELTA_WPARAM(w_param)) / static_cast<float>(WHEEL_DELTA);
                float y_offset = 0.0f;

                MouseScrolledEvent event(x_offset, y_offset);
                data->event_callback(event);

                return 0;
            }
            case WM_MOUSEMOVE:
            {
                float x = static_cast<float>(GET_X_LPARAM(l_param));
                float y = static_cast<float>(GET_Y_LPARAM(l_param));

                MouseMovedEvent event(x, y);
                data->event_callback(event);

                return 0;
            }
            case WM_CLOSE: {
                WindowCloseEvent event;
                data->event_callback(event);
                return 0;
            }
            case WM_SIZE: {
                UINT width = LOWORD(l_param);
                UINT height = HIWORD(l_param);
                data->width = width;
                data->height = height;

                WindowResizeEvent event(width, height);
                data->event_callback(event);

                return 0;
            }
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }
        return DefWindowProcW(hwnd, u_msg, w_param, l_param);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props) {
        init(props);
    }

    WindowsWindow::~WindowsWindow() {
        shutdown();
    }

    void WindowsWindow::init(const WindowProps& props) {
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        KAS_CORE_INFO("Creating window {0} {1}x{2}", props.title, props.width, props.height);

        win32::WindowConfig config;
        config.title = win32::string_to_wstring(props.title);
        config.width = props.width;
        config.height = props.height;
        config.resizable = true;
        config.center_on_screen = true;
        config.window_proc = window_proc;
        config.user_data = &m_data;

        HWND hwnd = win32::create_window(config);
        if (!hwnd) {
            KAS_CORE_ASSERT(false, "Win32 Window creation failed");
        }

        m_hwnd = hwnd;
    }

    void WindowsWindow::shutdown() {
        DestroyWindow(m_hwnd);
    }

    void WindowsWindow::on_update() {
        MSG msg = {};
        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
}

#endif
