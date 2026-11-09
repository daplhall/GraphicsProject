add_library(Memory
	mem.c
	alignment.c
)

add_library(Memory::mem ALIAS Memory)

target_include_directories(Memory
	PRIVATE
	.
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(Memory
	PRIVATE
	Options::compile
	Options::link
)
