#include "mem/arena/arena.h"
#include <stdint.h>

#define T hashmap

typedef struct T T;

struct T {
	int a;
};

T *
Hashmap_create (Arena *arena)
{
	return (T *)1;
}
