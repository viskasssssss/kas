add_executable(Testbed
    src/Main.cc
)

# Linking automatically pulls in EngineCore's include paths and ensures EngineCore builds first
target_link_libraries(Testbed PRIVATE Kas)
