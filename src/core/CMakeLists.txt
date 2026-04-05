add_library(Core
    arena.c
    mem.c
)

target_include_directories(Core
    PRIVATE
    .
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
