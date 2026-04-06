add_library(memspy
    OBJECT
    memspy.c
)

target_include_directories(memspy
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
