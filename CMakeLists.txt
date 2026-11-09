cmake_minimum_required(VERSION 4.2.3)

project(ComputerGraphics
    LANGUAGES
    C
    CXX
)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

include(cmake/project.options.cmake)

include(cmake/externals/FindSDL3.cmake)
include(cmake/externals/FindGoogleTest.cmake)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

enable_testing()

add_subdirectory(modules/shared)
add_subdirectory(modules/mem)
add_subdirectory(modules/arena)
add_subdirectory(src)

add_subdirectory(spies)
add_subdirectory(tests)
