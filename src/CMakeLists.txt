add_library(Core
    core/arena.c
    core/mem.c
)

target_include_directories(Core
    PRIVATE
    ./core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(Core
    PRIVATE
    ${RASTER_CFLAGS}
)

target_link_options(Core
    PUBLIC
    ${RASTER_LCFLAGS}
)

add_executable(main
    core/main.c
)

target_link_libraries(main
    PRIVATE
    Core
)
