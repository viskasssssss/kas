#pragma once

#include "Kas/Core/Defines.hh"

#include <memory>
#include <spdlog/spdlog.h>

namespace kas {
    class KAS_API Log {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
        inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }
    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };
}

#define KAS_CORE_CRITICAL(...) ::kas::Log::get_core_logger()->critical(__VA_ARGS__)
#define KAS_CORE_ERROR(...)    ::kas::Log::get_core_logger()->error(__VA_ARGS__)
#define KAS_CORE_WARN(...)     ::kas::Log::get_core_logger()->warn(__VA_ARGS__)
#define KAS_CORE_INFO(...)     ::kas::Log::get_core_logger()->info(__VA_ARGS__)
#define KAS_CORE_TRACE(...)    ::kas::Log::get_core_logger()->trace(__VA_ARGS__)

#define KAS_CRITICAL(...)      ::kas::Log::get_client_logger()->critical(__VA_ARGS__)
#define KAS_ERROR(...)         ::kas::Log::get_client_logger()->error(__VA_ARGS__)
#define KAS_WARN(...)          ::kas::Log::get_client_logger()->warn(__VA_ARGS__)
#define KAS_INFO(...)          ::kas::Log::get_client_logger()->info(__VA_ARGS__)
#define KAS_TRACE(...)         ::kas::Log::get_client_logger()->trace(__VA_ARGS__)
