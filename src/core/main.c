#include "core/arena.h"

int
main (int argc, char *argv[])
{
	Arena *arena = Arena_create (64, ARENA_STATIC);
	char *p = (char *)Arena_push (arena, 4, 1);
	*p = 4;
	Arena_release (arena);
}