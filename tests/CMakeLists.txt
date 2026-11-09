add_executable(SDL-tests
    SDL/main.cpp
    SDL/test_1.cpp
)

target_link_libraries(SDL-tests SDL3::SDL3)
target_link_libraries(SDL-tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(SDL-tests)
