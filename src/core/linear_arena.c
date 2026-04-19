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

static uintptr_t
alignment_forward (uintptr_t ptr_to_align, size_t align)
{
	return (ptr_to_align + align - 1) & ~(align - 1);
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
	uintptr_t aligned_ptr;
	size_t aligned_offset;

	assert (align != 0);
	assert (is_power_of_two (align));

	aligned_ptr
	    = alignment_forward ((uintptr_t)arena->mem + arena->offset, align);
	aligned_offset = aligned_ptr - (uintptr_t)arena->mem;

	if (nbytes + aligned_offset > arena->capcity) {
		arena->errno = ARENA_BAD_ALLOC;
		return NULL;
	}
	arena->errno = ARENA_OK;
	arena->offset += aligned_offset + nbytes;
	return (void *)aligned_ptr;
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