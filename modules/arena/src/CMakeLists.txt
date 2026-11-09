add_library(arena
	arena.c
	snapshot.c
)

add_library(Memory::arena ALIAS arena)

target_include_directories(arena
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../include
	PRIVATE
	./.
)

target_link_libraries(arena
	PRIVATE
	Memory::mem
	Foundation::shared
	Options::compile
	Options::link
)
