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
	size_t offset;
	char *mem;
};

struct _Arena {
	struct block *block;
	size_t capacity;
	enum Arena_error errno;
	enum Arena_type type;
};

struct AlignedMem {
	void *ptr;
	size_t offset;
};
#ifndef NDEBUG
static bool
is_power_of_two (size_t align)
{
	return !(align & (align - 1));
}
#endif

static void
allocate_block (T *arena, size_t bonus)
{
	struct block *new;
	new = (struct block *)ALLOC (sizeof (struct block) + arena->capacity
				     + bonus);
	*new = (struct block){
		.offset = 0,
		.mem = (char *)(new + 1),
		.next = arena->block,
	};
	arena->block = new;
}

T *
Arena_create (size_t reserve, enum Arena_type type)
{
	T *arena;

	arena = (T *)ALLOC (reserve + sizeof (T));
	if (arena == NULL) {
		return arena;
	}

	*arena = (T){
		.block = NULL,
		.capacity = reserve,
		.errno = ARENA_OK,
		.type = type,
	};

	allocate_block (arena, 0);

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

static bool
is_within_capacity (size_t offset, size_t capacity)
{
	return offset <= capacity;
}

static uintptr_t
alignment_forward (uintptr_t ptr_to_align, size_t align)
{
	return (ptr_to_align + align - 1) & ~(align - 1);
}

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

void *
Arena_push (T *arena, size_t nbytes, size_t align)
{
	struct AlignedMem aligned;

	assert (align != 0);
	assert (is_power_of_two (align));

	aligned = align_by_block (arena->block, align);

	if (!is_within_capacity (nbytes + aligned.offset, arena->capacity)) {
		switch (arena->type) {
		case ARENA_STATIC:
			arena->errno = ARENA_BAD_ALLOC;
			return NULL;
		case ARENA_DYNMAIC:
			allocate_block (arena, nbytes);
			aligned = align_by_block (arena->block, align);
			break;
		}
	}
	arena->errno = ARENA_OK;
	arena->block->offset += aligned.offset + nbytes;
	return (void *)aligned.ptr;
}

void
Arena_pop (T *arena, size_t nbytes)
{
	if (nbytes > arena->block->offset) {
		arena->block->offset = 0;
	} else {
		arena->block->offset -= nbytes;
	}
}

enum Arena_error
Arena_GetError (T *arena)
{
	return arena->errno;
}

size_t
Arena_capacity (T *arena)
{
	return arena->capacity;
}

size_t
Arena_allocated (T *arena)
{
	return arena->block->offset;
}