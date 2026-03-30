add_library(Arenas
    stack_arena.c
)

target_include_directories(Arenas
    PRIVATE
    .
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
