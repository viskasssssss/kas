#pragma once

#include <memory>

namespace kas {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> create_scope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> create_ref(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#define KAS_EXPAND_MACRO(x) x
#define KAS_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define KAS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

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

#ifdef KAS_DEBUG
	#if defined(KAS_PLATFORM_WINDOWS)
		#define KAS_DEBUGBREAK() __debugbreak()
	#elif defined(KAS_PLATFORM_LINUX)
		#include <signal.h>
		#define KAS_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error Unsupported platform
	#endif
	#define KAS_ENABLE_ASSERTS
#else
	#define KAS_DEBUGBREAK()
#endif

#include "Kas/Core/Assert.hh"
