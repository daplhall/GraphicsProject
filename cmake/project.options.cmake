add_library(compile_options
	INTERFACE
)

add_library(Options::compile ALIAS compile_options)

target_compile_options(compile_options
	INTERFACE
	${RASTER_CFLAGS}
)

add_library(linker_options
	INTERFACE
)

add_library(Options::link ALIAS linker_options)

target_compile_options(linker_options
	INTERFACE
	${RASTER_LCFLAGS}
)
