add_library(arena
	src/arena.c
)

add_library(MyLib::mem ALIAS mem)

target_include_directories(mem
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(arena
	PUBLIC Memory::mem
)
