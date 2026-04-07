#include "core/arena.h"
#include "core/mem.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#define T Arena
#define ALIGNMENT

struct _Arena {
	size_t capcity;
	size_t offset;
	enum Arena_error errno;
	char *mem;
};

static bool
is_power_of_two (size_t align)
{
	return !(align & (align - 1));
}

T *
Arena_create (size_t capacity, enum Arena_type type)
{
	T *mem = (T *)ALLOC (capacity + sizeof (T));
	if (mem == NULL) {
		return mem;
	}
	*mem = (T){
		.mem = (char *)(mem + 1),
		.offset = 0,
		.capcity = capacity,
		.errno = ARENA_OK,
	};
	return mem;
}

void
Arena_release (T *arena)
{
	FREE (arena);
}

void *
Arena_push (T *arena, size_t nbytes, size_t align)
{
	assert (align != 0);
	assert (is_power_of_two (align));
	size_t aligned_offset = ((intptr_t)arena->mem + arena->offset) % align;
	size_t out_offset = 0;
	if (nbytes + aligned_offset > arena->capcity) {
		arena->errno = ARENA_BAD_ALLOC;
		return NULL;
	}
	arena->errno = ARENA_OK;
	out_offset = arena->offset + aligned_offset;
	arena->offset = out_offset + nbytes;
	return arena->mem + out_offset;
}

enum Arena_error
Arena_GetError (T *arena)
{
	return arena->errno;
}

size_t
Arena_occupied (T *arena)
{
	return arena->offset;
}