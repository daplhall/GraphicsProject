add_executable(main
    main.c
)

target_link_libraries(main
    PRIVATE
    SDL3::SDL3
)

target_compile_options(main
    PRIVATE
    ${RASTER_CFLAGS}
)

target_link_options(main
    PRIVATE
    ${RASTER_LCFLAGS}
)
