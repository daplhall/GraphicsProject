add_executable(mem-tests
    mem/mem.cpp
)
target_link_libraries(mem-tests
    GTest::gtest_main
    Memory
)

target_include_directories(mem-tests
    PUBLIC
    .
)

add_executable(arena-tests
    mem/arena.cpp
    mem/pool.cpp
)
target_link_libraries(arena-tests
    GTest::gtest_main
    memspy
    Memory
)
target_include_directories(arena-tests
    PUBLIC
    ./mem
)

target_compile_options(Memory
    PRIVATE
    ${RASTER_SANITIZER_FLAGS}
)

target_link_options(Memory
    PUBLIC
    ${RASTER_LCFLAGS}
)

add_executable(collections-tests
    collections/hashmap.cpp
)

target_link_libraries(collections-tests
    PUBLIC
    GTest::gtest_main
    memspy
    Memory
    collections
)


#add_executable(SDL-tests
#    SDL/main.cpp
#    SDL/test_1.cpp
#)

#target_link_libraries(SDL-tests SDL3::SDL3)
#target_link_libraries(SDL-tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(mem-tests)
gtest_discover_tests(arena-tests)
#gtest_discover_tests(SDL-tests)
gtest_discover_tests(collections-tests)
