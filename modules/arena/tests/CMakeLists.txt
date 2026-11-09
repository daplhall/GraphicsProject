add_executable(arena-tests
    arena.cpp
)
target_link_libraries(arena-tests
    GTest::gtest_main
    memspy
    Memory::arena
)

include(GoogleTest)
gtest_discover_tests(arena-tests)
