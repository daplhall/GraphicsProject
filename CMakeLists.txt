cmake_minimum_required(VERSION 4.2.3)

project(ComputerGraphics
    LANGUAGES
    C
    CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(src)

enable_testing()
include(cmake/FindGoogleTest.cmake)
include(cmake/FindSDL.cmake)
