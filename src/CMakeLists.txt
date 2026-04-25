add_library(Core
    core/arena.c
    core/pool.c
    core/mem.c
    core/alignment.c
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
