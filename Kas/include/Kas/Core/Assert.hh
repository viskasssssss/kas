#pragma once

#include "Kas/Core/Defines.hh"
#include "Kas/Core/Log.hh"
#include <filesystem>

#ifdef KAS_ENABLE_ASSERTS
	#define KAS_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { KAS##type##ERROR(msg, __VA_ARGS__); KAS_DEBUGBREAK(); } }
	#define KAS_INTERNAL_ASSERT_WITH_MSG(type, check, ...) KAS_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define KAS_INTERNAL_ASSERT_NO_MSG(type, check) KAS_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", KAS_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define KAS_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define KAS_INTERNAL_ASSERT_GET_MACRO(...) KAS_EXPAND_MACRO( KAS_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, KAS_INTERNAL_ASSERT_WITH_MSG, KAS_INTERNAL_ASSERT_NO_MSG) )

	#define KAS_ASSERT(...) KAS_EXPAND_MACRO( KAS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define KAS_CORE_ASSERT(...) KAS_EXPAND_MACRO( KAS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define KAS_ASSERT(...)
	#define KAS_CORE_ASSERT(...)
#endif