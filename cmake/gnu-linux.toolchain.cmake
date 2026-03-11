set(CMAKE_SYSTEM_NAME Linux)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(RASTER_CONFIG_FLAGS "-g3" "-O0")
    set(RASTER_SANITIZER_FLAGS "-fsanitize=address" "-fsanitize=leak")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(RASTER_CONFIG_FLAGS "-O3")
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
)

set(RASTER_CFLAGS
    ${RASTER_CONFIG_FLAGS}
    ${RASTER_SANITIZER_FLAGS}
    ${RASTER_WARNINGS_FLAGS}
)
set(RASTER_LCFLAGS
    ${RASTER_SANITIZER_FLAGS}
)
