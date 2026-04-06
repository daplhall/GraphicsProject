add_executable(core-tests
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

add_executable(arena-tests
    arena.cpp
)
target_link_libraries(arena-tests
    GTest::gtest_main
    memspy
    Core
)
target_include_directories(arena-tests
    PUBLIC
    .
)



include(GoogleTest)
gtest_discover_tests(core-tests)
gtest_discover_tests(arena-tests)
