#include "core/arena.h"

#define T Arena

struct _Arena {
	int a;
};

T *
Arena_create (size_t capacity)
{
	return (T *)1;
}

void
Arena_release (T *arena)
{
}
