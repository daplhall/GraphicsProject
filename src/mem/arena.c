/*
 * This file defines a simple scratch arena which allocated linearly
 * Scratch means it allocated and never deallocates execpt when they arena
 * is destroyied.
 */
#include "mem/arena.h"
#include "alignment.h"
#include "mem/mem.h"
#include <assert.h>
#include <complex.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define T Arena
#define P ArenaTemp
#define ALIGNMENT

#ifndef NDEBUG
static bool
is_power_of_two (size_t align)
{
	return !(align & (align - 1));
}
#endif

struct block {
	struct block *next;
	char *mem;
	size_t offset;
	size_t capacity;
};

struct _Arena {
	struct block *block;
	enum Arena_error errno;
	enum Arena_type type;
};

struct AlignedMem {
	void *ptr;
	size_t offset;
};

static struct AlignedMem
align_by_block (struct block *block, size_t align)
{
	uintptr_t aligned_ptr
	    = alignment_forward ((uintptr_t)block->mem + block->offset, align);

	return (struct AlignedMem){
		.ptr = (char *)aligned_ptr,
		.offset = aligned_ptr - (uintptr_t)block->mem,
	};
}

static void
allocate_block (T *arena, size_t extra)
{
	struct block *new;
	size_t block_capacity = arena->block->capacity + extra;
	new = (struct block *)ALLOC (sizeof (struct block) + block_capacity);
	*new = (struct block){
		.offset = 0,
		.capacity = block_capacity,
		.mem = (char *)(new + 1),
		.next = arena->block,
	};
	arena->block = new;
}

static void
init (void *ptr, size_t capacity, enum Arena_type type)
{
	T *arena = (T *)ptr;
	*arena = (T){
		.block = (struct block *)(arena + 1),
		.errno = ARENA_OK,
		.type = type,
	};

	*arena->block = (struct block){
		.offset = 0,
		.capacity = capacity,
		.mem = (char *)(arena->block + 1),
		.next = NULL,
	};
}

T *
Arena_create (size_t reserve, enum Arena_type type)
{
	T *arena;
	assert ((alignof (T) % alignof (struct block)) == 0);

	arena = ALLOC (reserve + sizeof (T) + sizeof (struct block));
	if (arena == NULL) {
		return arena;
	}

	init (arena, reserve, type);

	return arena;
}

void
Arena_release (T *arena)
{
	while (arena->block->next != NULL) {
		struct block *old = arena->block;
		arena->block = old->next;
		FREE (old);
	}
	FREE (arena);
}

static bool
is_within_capacity (size_t offset, size_t capacity)
{
	return offset <= capacity;
}

void *
Arena_push (T *arena, size_t nbytes, size_t align)
{
	struct AlignedMem aligned;

	assert (align != 0);
	assert (is_power_of_two (align));

	aligned = align_by_block (arena->block, align);

	if (!is_within_capacity (nbytes + aligned.offset,
				 arena->block->capacity)) {
		switch (arena->type) {
		case ARENA_STATIC:
			arena->errno = ARENA_BAD_ALLOC;
			return NULL;
		case ARENA_DYNAMIC:
			allocate_block (arena, nbytes);
			aligned = align_by_block (arena->block, align);
			break;
		}
	}
	arena->errno = ARENA_OK;
	arena->block->offset += aligned.offset + nbytes;
	return (void *)aligned.ptr;
}

enum Arena_error
Arena_GetError (T *arena)
{
	return arena->errno;
}

enum Arena_error
Arena_setpos (T *arena, size_t pos)
{
	if (pos > arena->block->capacity) {
		arena->errno = ARENA_BAD_POSITION;
		return ARENA_BAD_POSITION;
	}
	arena->block->offset = pos;
	return ARENA_OK;
}

void
Arena_clear (T *arena)
{
}

P
ArenaTemp_create (T *arena)
{
	return (P){ .arena = arena, .loc = arena->block->offset };
}

void
ArenaTemp_release (P *temp_arena)
{
}
