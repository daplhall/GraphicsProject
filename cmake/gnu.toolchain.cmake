set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_CXX_COMPILER "g++")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(RASTER_CONFIG_FLAGS "-g3" "-Og")
    set(RASTER_SANITIZER_FLAGS "-fsanitize=address" "-fsanitize=leak")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(RASTER_CONFIG_FLAGS "-O3" "-D_FORTIFY_SOURCE=2")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(RASTER_CONFIG_FLAGS "-O2")
    set(RASTER_SANITIZER_FLAGS  "-fsanitize=address,undefined,leak")
endif()

set(RASTER_WARNINGS_FLAGS
    "-Wall"
    "-Werror"
    "-Wextra"
    "-Wpedantic"
    "-Wformat=2"
    "-Wno-unused-parameter"
    "-Wshadow"
    "-Wwrite-strings"
    "-Wstrict-prototypes"
    "-Wold-style-definition"
    "-Wredundant-decls"
    "-Wnested-externs"
    "-Wmissing-include-dirs"
    "-Wuninitialized"
    "-Wno-error=pedantic"
    #"-Wpadded"
)

set(RASTER_CFLAGS
    ${RASTER_CONFIG_FLAGS}
    ${RASTER_SANITIZER_FLAGS}
    ${RASTER_WARNINGS_FLAGS}
)
set(RASTER_LCFLAGS
    ${RASTER_SANITIZER_FLAGS}
)


execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json
)
