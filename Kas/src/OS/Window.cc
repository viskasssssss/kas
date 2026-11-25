#include "kpch.hh"
#include "Kas/OS/Window.hh"

#ifdef KAS_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.hh"
#endif

namespace kas {
    Scope<Window> Window::create(const WindowProps& props) {
    #ifdef KAS_PLATFORM_WINDOWS
        return create_scope<WindowsWindow>(props);
    #else
        KAS_CORE_ASSERT(false, "Unknown platform");
        return nullptr;
    #endif
    }
}