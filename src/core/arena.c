#include "core/arena.h"
#include "core/mem.h"

#define T Arena

struct _Arena {
	size_t capcity;
	size_t offset;
	enum Arena_error errno;
	char *mem;
};

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
Arena_push (T *arena, size_t nbytes)
{
	if (nbytes + arena->offset > arena->capcity) {
		arena->errno = ARENA_BAD_ALLOC;
		return NULL;
	}
	arena->errno = ARENA_OK;
	arena->offset += nbytes;
	return arena->mem + arena->offset;
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