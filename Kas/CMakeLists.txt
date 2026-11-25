add_library(Kas SHARED
    # src/Core
    src/Core/Application.cc
    src/Core/Log.cc

    # src/Event
    src/Event/Event.cc
    src/Event/ApplicationEvent.cc
    src/Event/KeyEvent.cc
    src/Event/MouseEvent.cc

    # src/OS
    src/OS/Window.cc

    # src/Platform
    #           /Windows
    src/Platform/Windows/WindowsSys.cc
    src/Platform/Windows/WindowsWindow.cc
)

target_link_libraries(Kas PRIVATE spdlog::spdlog)

target_compile_definitions(Kas PRIVATE
    $<$<CONFIG:Debug>:KAS_DEBUG>
)

target_precompile_headers(Kas PRIVATE "include/kpch.hh")

target_compile_definitions(Kas PRIVATE KAS_BUILD_DLL UNICODE)

target_include_directories(Kas PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
