add_executable(datastructures-tests
    array.cpp
)

target_link_libraries(datastructures-tests
    GTest::gtest_main
    DataStructures
)

include(GoogleTest)
gtest_discover_tests(datastructures-tests)
