add_library(Memory
    mem/arena.c
    mem/pool.c
    mem/mem.c
    mem/alignment.c
)

target_include_directories(Memory
    PRIVATE
    ./mem
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(Memory
    PRIVATE
    ${RASTER_CFLAGS}
)

target_link_options(Memory
    PUBLIC
    ${RASTER_LCFLAGS}
)
