#include "gtest/gtest.h"
#include <SDL3/SDL_main.h>
#include <stdbool.h>


int
main (int argc, char *argv[])
{
	SDL_SetMainReady ();

	if (!static_cast<bool>(SDL_Init (SDL_INIT_VIDEO))) {
		std::cout << "FATAL: Cannot init SDL: " << SDL_GetError () << "\n";
		return -1;
	}

	::testing::InitGoogleTest (&argc, argv);
	int result = RUN_ALL_TESTS (); 

	SDL_Quit (); 
	return result; 
}
