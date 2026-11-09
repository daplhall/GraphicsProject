add_library(memspy
    OBJECT
    mem/memspy.c
)

target_include_directories(memspy
    PUBLIC
    ${PROJECT_SOURCE_DIR}/modules/mem/include
    ${PROJECT_SOURCE_DIR}/spies/mem
    PRIVATE
    ${PROJECT_SOURCE_DIR}/modules/mem/src/
)
