cmake_minimum_required(VERSION 4.2.3)

project(ComputerGraphics
    LANGUAGES
    C
    CXX
)

include(cmake/FindGoogleTest.cmake)
include(cmake/FindSDL3.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_subdirectory(src)

enable_testing()
add_subdirectory(spies)
add_subdirectory(tests)
