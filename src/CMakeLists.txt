add_executable(SDL-runtime
	main.c
)

target_link_libraries(SDL-runtime 
	PRIVATE 
	SDL3::SDL3
)
