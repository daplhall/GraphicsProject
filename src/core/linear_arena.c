#include "core/arena.h"
#include "core/mem.h"
#include <assert.h>
#include <complex.h>
#include <stdbool.h>
#include <stdint.h>

#define T Arena
#define ALIGNMENT

struct block {
	struct block *next;
	size_t capcity;
	size_t offset;
	char *mem;
};

struct _Arena {
	struct block *block;
	enum Arena_error errno;
	enum Arena_type type;
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
	T *arena;
	struct block *block;

	arena = (T *)ALLOC (capacity + sizeof (T));
	if (arena == NULL) {
		return arena;
	}

	block = (struct block *)ALLOC (capacity + sizeof (struct block));
	*block = (struct block){
		.next = NULL,
		.mem = (char *)(block + 1),
		.capcity = capacity,
		.offset = 0,
	};

	*arena = (T){
		.block = block,
		.errno = ARENA_OK,
		.type = type,
	};

	return arena;
}

void
Arena_release (T *arena)
{
	while (arena->block != NULL) {
		struct block *old = arena->block;
		arena->block = old->next;
		FREE (old);
	}
	FREE (arena);
}

static void *
static_push (T *arena, size_t nbytes, size_t align)
{
	uintptr_t aligned_ptr;
	size_t aligned_offset;

	assert (align != 0);
	assert (is_power_of_two (align));

	aligned_ptr = alignment_forward (
	    (uintptr_t)arena->block->mem + arena->block->offset, align);
	aligned_offset = aligned_ptr - (uintptr_t)arena->block->mem;

	if (nbytes + aligned_offset > arena->block->capcity) {
		arena->errno = ARENA_BAD_ALLOC;
		return NULL;
	}
	arena->errno = ARENA_OK;
	arena->block->offset += aligned_offset + nbytes;
	return (void *)aligned_ptr;
}

static void *
dynamic_push (T *arena, size_t nbytes, size_t align)
{
	uintptr_t aligned_ptr;
	size_t aligned_offset;

	assert (align != 0);
	assert (is_power_of_two (align));

	aligned_ptr = alignment_forward (
	    (uintptr_t)arena->block->mem + arena->block->offset, align);
	aligned_offset = aligned_ptr - (uintptr_t)arena->block->mem;
	if (nbytes + aligned_offset > arena->block->capcity) {
		struct block *new = (struct block *)ALLOC (
		    sizeof (struct block) + arena->block->capcity);
		*new = (struct block){
			.capcity = arena->block->capcity,
			.offset = 0,
			.mem = (char *)(new + 1),
			.next = arena->block,
		};
		arena->block = new;
		aligned_ptr = alignment_forward (
		    (uintptr_t)arena->block->mem + arena->block->offset, align);
		aligned_offset = aligned_ptr - (uintptr_t)arena->block->mem;
	}
	arena->errno = ARENA_OK;
	arena->block->offset += aligned_offset + nbytes;
	return (void *)aligned_ptr;
}

void *
Arena_push (T *arena, size_t nbytes, size_t align)
{
	switch (arena->type) {
	case ARENA_STATIC:
		return static_push (arena, nbytes, align);
	case ARENA_DYNMAIC:
		return dynamic_push (arena, nbytes, align);
	default:
		arena->errno = ARENA_BAD_TYPE;
		return 0;
	}
}

enum Arena_error
Arena_GetError (T *arena)
{
	return arena->errno;
}

size_t
Arena_occupied (T *arena)
{
	return arena->block->offset;
}