add_library(arena
	arena.c
)

add_library(Memory::arena ALIAS arena)

target_include_directories(arena
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(arena
	PRIVATE
	Memory::mem
	Foundation::shared
)
