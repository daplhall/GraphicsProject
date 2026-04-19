add_library(Core
    linear_arena.c
    mem.c
)

target_include_directories(Core
    PRIVATE
    .
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
