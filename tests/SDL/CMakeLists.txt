add_executable(core-tests
    main.cpp
    test_1.cpp
)

target_link_libraries(core-tests SDL3::SDL3)
target_link_libraries(core-tests GTest::gtest_main)
