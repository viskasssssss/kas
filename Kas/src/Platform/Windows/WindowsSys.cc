#include "kpch.hh"

#ifdef _WIN32

#include "Platform/Windows/WindowsSys.hh"

namespace kas::win32 {
    KeyCode win32_to_native_key_code(WPARAM w_param, LPARAM l_param) {
        UINT scancode = (l_param & 0x00FF0000) >> 16;
        bool is_extended = (l_param & (1 << 24)) != 0;

        UINT full_scancode = is_extended ? (0xE000 | scancode) : scancode;

        switch (full_scancode)
        {
            case 0x0029: return Key::GraveAccent;  // `
            case 0x0002: return Key::D1;
            case 0x0003: return Key::D2;
            case 0x0004: return Key::D3;
            case 0x0005: return Key::D4;
            case 0x0006: return Key::D5;
            case 0x0007: return Key::D6;
            case 0x0008: return Key::D7;
            case 0x0009: return Key::D8;
            case 0x000A: return Key::D9;
            case 0x000B: return Key::D0;
            case 0x000C: return Key::Minus;        // -
            case 0x000D: return Key::Equal;        // =

            case 0x0010: return Key::Q;
            case 0x0011: return Key::W;
            case 0x0012: return Key::E;
            case 0x0013: return Key::R;
            case 0x0014: return Key::T;
            case 0x0015: return Key::Y;
            case 0x0016: return Key::U;
            case 0x0017: return Key::I;
            case 0x0018: return Key::O;
            case 0x0019: return Key::P;
            case 0x001A: return Key::LeftBracket;  // [
            case 0x001B: return Key::RightBracket; // ]
            case 0x002B: return Key::Backslash;    // '\'

            case 0x001E: return Key::A;
            case 0x001F: return Key::S;
            case 0x0020: return Key::D;
            case 0x0021: return Key::F;
            case 0x0022: return Key::G;
            case 0x0023: return Key::H;
            case 0x0024: return Key::J;
            case 0x0025: return Key::K;
            case 0x0026: return Key::L;
            case 0x0027: return Key::Semicolon;    // ;
            case 0x0028: return Key::Apostrophe;   // '

            case 0x0056: return Key::World1;       // Non-US < > | key
            case 0x002C: return Key::Z;
            case 0x002D: return Key::X;
            case 0x002E: return Key::C;
            case 0x002F: return Key::V;
            case 0x0030: return Key::B;
            case 0x0031: return Key::N;
            case 0x0032: return Key::M;
            case 0x0033: return Key::Comma;        // ,
            case 0x0034: return Key::Period;       // .
            case 0x0035: return Key::Slash;        // /

            case 0x0001: return Key::Escape;
            case 0x003B: return Key::F1;
            case 0x003C: return Key::F2;
            case 0x003D: return Key::F3;
            case 0x003E: return Key::F4;
            case 0x003F: return Key::F5;
            case 0x0040: return Key::F6;
            case 0x0041: return Key::F7;
            case 0x0042: return Key::F8;
            case 0x0043: return Key::F9;
            case 0x0044: return Key::F10;
            case 0x0057: return Key::F11;
            case 0x0058: return Key::F12;
            case 0x0064: return Key::F13;
            case 0x0065: return Key::F14;
            case 0x0066: return Key::F15;
            case 0x0067: return Key::F16;
            case 0x0068: return Key::F17;
            case 0x0069: return Key::F18;
            case 0x006A: return Key::F19;
            case 0x006B: return Key::F20;
            case 0x006C: return Key::F21;
            case 0x006D: return Key::F22;
            case 0x006E: return Key::F23;
            case 0x0076: return Key::F24;

            case 0x000E: return Key::Backspace;
            case 0x000F: return Key::Tab;
            case 0x001C: return Key::Enter;
            case 0x0039: return Key::Space;
            case 0x003A: return Key::CapsLock;
            case 0x002A: return Key::LeftShift;
            case 0x0036: return Key::RightShift;
            case 0x001D: return Key::LeftControl;
            case 0xE01D: return Key::RightControl;
            case 0x0038: return Key::LeftAlt;
            case 0xE038: return Key::RightAlt;
            case 0xE05B: return Key::LeftSuper;
            case 0xE05C: return Key::RightSuper;
            case 0xE05D: return Key::Menu;

            case 0xE037: return Key::PrintScreen;
            case 0x0046: return Key::ScrollLock;
            case 0x0045: return (w_param == VK_NUMLOCK) ? Key::NumLock : Key::Pause;
            case 0xE045: return Key::NumLock;
            case 0xE046: return Key::Pause;
            case 0xE052: return Key::Insert;
            case 0xE053: return Key::Delete;
            case 0xE047: return Key::Home;
            case 0xE04F: return Key::End;
            case 0xE049: return Key::PageUp;
            case 0xE051: return Key::PageDown;
            case 0xE048: return Key::Up;
            case 0xE050: return Key::Down;
            case 0xE04B: return Key::Left;
            case 0xE04D: return Key::Right;

            case 0x0052: return Key::KP0;
            case 0x004F: return Key::KP1;
            case 0x0050: return Key::KP2;
            case 0x0051: return Key::KP3;
            case 0x004B: return Key::KP4;
            case 0x004C: return Key::KP5;
            case 0x004D: return Key::KP6;
            case 0x0047: return Key::KP7;
            case 0x0048: return Key::KP8;
            case 0x0049: return Key::KP9;
            case 0x0053: return Key::KPDecimal;
            case 0xE035: return Key::KPDivide;
            case 0x0037: return Key::KPMultiply;
            case 0x004A: return Key::KPSubtract;
            case 0x004E: return Key::KPAdd;
            case 0xE01C: return Key::KPEnter;
            case 0x0059: return Key::KPEqual;

            default:     return 0;
        }
    }

    MouseCode win32_to_native_mouse_code(UINT u_msg, WPARAM w_param) {
        switch (u_msg)
        {
            case WM_LBUTTONDOWN:
            case WM_LBUTTONUP:
            case WM_LBUTTONDBLCLK:
                return Mouse::ButtonLeft;

            case WM_RBUTTONDOWN:
            case WM_RBUTTONUP:
            case WM_RBUTTONDBLCLK:
                return Mouse::ButtonRight;

            case WM_MBUTTONDOWN:
            case WM_MBUTTONUP:
            case WM_MBUTTONDBLCLK:
                return Mouse::ButtonMiddle;

            case WM_XBUTTONDOWN:
            case WM_XBUTTONUP:
            case WM_XBUTTONDBLCLK:
            {
                WORD xButton = GET_XBUTTON_WPARAM(w_param);
                if (xButton == XBUTTON1) return Mouse::Button3;
                if (xButton == XBUTTON2) return Mouse::Button4;
                break;
            }
        }

        return static_cast<MouseCode>(-1);
    }
    
    std::wstring string_to_wstring(const std::string& str) {
        if (str.empty()) return std::wstring();
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        std::wstring wstrTo(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
        return wstrTo;
    }

    HWND create_window(const WindowConfig& config) {
        SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

        HINSTANCE hInstance = GetModuleHandleW(nullptr);
        const wchar_t* className = L"KasWindowClass";

        static bool isClassRegistered = false;
        if (!isClassRegistered) {
            WNDCLASSEXW wc = {};
            wc.cbSize        = sizeof(WNDCLASSEXW);
            wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
            wc.lpfnWndProc   = config.window_proc;
            wc.hInstance     = hInstance;
            wc.hIcon         = LoadIconW(nullptr, IDI_APPLICATION);
            wc.hCursor       = LoadCursorW(nullptr, IDC_ARROW);
            wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
            wc.lpszClassName = className;
            wc.hIconSm       = LoadIconW(nullptr, IDI_APPLICATION);

            if (!RegisterClassExW(&wc)) {
                return nullptr;
            }
            isClassRegistered = true;
        }

        DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
        if (config.resizable) {
            style |= WS_THICKFRAME | WS_MAXIMIZEBOX;
        }
        DWORD exStyle = WS_EX_APPWINDOW;

        RECT rect = { 0, 0, config.width, config.height };
        AdjustWindowRectEx(&rect, style, FALSE, exStyle);
        int windowWidth  = rect.right - rect.left;
        int windowHeight = rect.bottom - rect.top;

        int posX = CW_USEDEFAULT;
        int posY = CW_USEDEFAULT;
        if (config.center_on_screen) {
            int screenWidth  = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);
            posX = (screenWidth - windowWidth) / 2;
            posY = (screenHeight - windowHeight) / 2;
        }

        HWND hwnd = CreateWindowExW(
            exStyle,
            className,
            config.title.c_str(),
            style,
            posX, posY,
            windowWidth, windowHeight,
            nullptr,
            nullptr,
            hInstance,
            config.user_data
        );

        if (!hwnd) {
            return nullptr;
        }

        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(config.user_data));

        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);

        return hwnd;
    }
}

#endif
