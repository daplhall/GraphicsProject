# How an SDL program runs.
Because Windows and UNIX have different ways to enter a program we need to use SDLs own program start syntax.

For this there are 3 callback functions that need to be defined.
1. SDL_AppInit - Initializes the program, ie runs on start up
2. SDL_AppIterate - Runs once pr frame, the heart of the programs logic
3. SDL_AppQuit - Runs on shutdown

These only need to be defined if `SDL_MAIN_USE_CALLBACKS` is defined.

# Event base input
2. SDL_AppEvent