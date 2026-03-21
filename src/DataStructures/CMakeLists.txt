add_library(DataStructures
    arrays/int.c
)

target_include_directories(DataStructures
    PRIVATE
    .
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
