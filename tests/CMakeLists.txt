add_executable(core-tests
    core/mem.cpp
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
    core/arena.cpp
    core/pool.cpp
)
target_link_libraries(arena-tests
    GTest::gtest_main
    memspy
    Core
)
target_include_directories(arena-tests
    PUBLIC
    ./core
)

target_compile_options(Core
    PRIVATE
    ${RASTER_SANITIZER_FLAGS}
)

target_link_options(Core
    PUBLIC
    ${RASTER_LCFLAGS}
)

add_executable(SDL-tests
    SDL/main.cpp
    SDL/test_1.cpp
)

target_link_libraries(SDL-tests SDL3::SDL3)
target_link_libraries(SDL-tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(core-tests)
gtest_discover_tests(arena-tests)
gtest_discover_tests(SDL-tests)
