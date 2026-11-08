add_library(mem
	src/mem.c
	src/alignment.c
)

add_library(Memory::mem ALIAS mem)

target_include_directories(mem
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
