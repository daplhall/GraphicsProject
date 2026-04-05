add_executable(core-tests
    arena.cpp
    mem.cpp
)

target_link_libraries(core-tests
    GTest::gtest_main
    Core
)

target_include_directories(core-tests
    PUBLIC
    .
)

include(GoogleTest)
gtest_discover_tests(core-tests)
