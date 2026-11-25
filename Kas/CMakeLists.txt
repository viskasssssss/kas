add_library(Kas SHARED
    src/Core/Application.cc
    src/Core/Log.cc
)

target_link_libraries(Kas PRIVATE spdlog::spdlog)

target_compile_definitions(Kas PRIVATE KAS_BUILD_DLL)

target_include_directories(Kas PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
