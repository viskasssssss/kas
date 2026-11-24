#pragma once

#ifdef _WIN32
    #define KAS_PLATFORM_WINDOWS
    #ifdef KAS_BUILD_DLL
        #define KAS_API __declspec(dllexport)
    #else
        #define KAS_API __declspec(dllimport)
    #endif
#else
    #error Unsupported platform
#endif
