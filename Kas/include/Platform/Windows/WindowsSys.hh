#pragma once

#include "kpch.hh"

#ifdef _WIN32

#ifndef UNICODE
    #define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif

#include "Kas/Input/KeyCode.hh"
#include "Kas/Input/MouseCode.hh"

namespace kas::win32 {
    template <typename T>
    T* get_window_user_data(HWND hwnd) {
        return reinterpret_cast<T*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    }

    KeyCode win32_to_native_key_code(WPARAM w_param, LPARAM l_param);
    MouseCode win32_to_native_mouse_code(UINT u_msg, WPARAM w_param);

    std::wstring string_to_wstring(const std::string& str);

    struct WindowConfig {
        std::wstring title = L"Kas Engine";
        int width = 1280;
        int height = 720;
        bool resizable = true;
        bool center_on_screen = true;
        WNDPROC window_proc = DefWindowProcW;
        void* user_data = nullptr;
    };

    HWND create_window(const WindowConfig& config);
}

#endif