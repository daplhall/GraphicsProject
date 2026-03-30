add_executable(arenas-tests
    stack_arena.cpp
)

target_link_libraries(arenas-tests
    GTest::gtest_main
    Arenas
)

include(GoogleTest)
gtest_discover_tests(arenas-tests)
