#include "arenas/stack_arena.h"

#define T _StackArena

struct T {
	int a;
};

struct T *
Arena_StackAlloc (size_t capacity)
{
	return (struct T *)1;
}