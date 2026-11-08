add_executable(mem-tests
    mem.cpp
)

target_link_libraries(mem-tests
    GTest::gtest_main
    Memory::mem
)

target_include_directories(mem-tests
    PUBLIC
    .
)

target_compile_options(Memory
    PRIVATE
    ${RASTER_SANITIZER_FLAGS}
)

target_link_options(Memory
    PUBLIC
    ${RASTER_LCFLAGS}
)

include(GoogleTest)
gtest_discover_tests(mem-tests)
