cmake_minimum_required(VERSION 4.2.3)

project(ComputerGraphics
    LANGUAGES
    C
    CXX
)


include(cmake/externals/FindGoogleTest.cmake)
include(cmake/project.options.cmake)
#include(cmake/FindSDL3.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

enable_testing()

add_subdirectory(modules/shared)
add_subdirectory(modules/mem)
add_subdirectory(modules/arena)

add_subdirectory(spies)
#add_subdirectory(modules/mem/tests)
#add_subdirectory(modules/arena/tests)
#add_subdirectory(tests)
