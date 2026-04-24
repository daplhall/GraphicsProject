add_library(memspy
    OBJECT
    core/memspy.c
    core/arenaspy.c
)

target_include_directories(memspy
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/spies/core
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src/core
)
