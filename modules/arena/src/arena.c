/*
 * TODO Checkpoints
 * TODO Checkpoints Dynamcic -- Deallocate from offset
 */
#include "arena/arena.h"
#include "mem/mem.h"
#include "shared/foundation.h"
#include "shared/intrusivelist.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define T	    _Arena
#define ArenaOffset size_t

#ifndef NDEBUG
static bool
is_power_of_two (size_t align)
{
	return !(align & (align - 1));
}
#endif

struct MemoryBlock {
	struct Node node;
	size_t size;
	ArenaOffset offset;
	char *block;
};

struct T {
	struct MemoryBlock *bottom;
	size_t size;
	enum Arena_type type;
};

static inline void
block_init (struct MemoryBlock *list, size_t reserve)
{
	*list = (struct MemoryBlock){ 
		.node = (struct Node){
			.prev = NULL,
			.next = NULL,
		},
		.size = reserve,
		.offset = 0,
		.block = (char *)(list + 1) };
}

struct T *
Arena_create (size_t reserve, enum Arena_type type)
{
	struct T *arena;
	struct MemoryBlock *list;

	if ((arena = CALLOC (1, sizeof (struct T))) == NULL) {
		return NULL;
	}

	if ((list = ALLOC (sizeof (struct MemoryBlock) + reserve)) == NULL) {
		FREE (arena);
		return NULL;
	}

	block_init (list, reserve);
	*arena = (struct T){ .bottom = list, .size = reserve, .type = type };

	return arena;
}

void
Arena_release (struct T *arena)
{
	struct Node *node = &arena->bottom->node;
	while (node != NULL) {
		struct MemoryBlock *list;
		list = container_of (node, struct MemoryBlock, node);
		node = list->node.prev;
		FREE (list);
	}
	FREE (arena);
}

static void *
static_push (struct T *arena, size_t nbytes, size_t alignment)
{
	struct MemoryBlock *memb = arena->bottom;
	uintptr_t next_adress = (uintptr_t)(memb->block + memb->offset);
	uintptr_t padding = (-next_adress) & (alignment - 1);
	// = (alignment - (next_adress % alignment)) % alignment
	size_t additional;
	size_t remaning;

	if (nbytes > SIZE_MAX - padding)
		return NULL;

	additional = nbytes + padding;
	remaning = memb->size - memb->offset;

	if (additional > remaning)
		return NULL;

	memb->offset += additional;
	return (void *)(next_adress + padding);
}

static void *
dynamic_push (struct T *arena, size_t nbytes, size_t alignment)
{

	struct MemoryBlock *memb = arena->bottom;
	struct MemoryBlock *new_block = NULL;
	uintptr_t next_adress, padding;
	size_t new_size;
	char *ptr;

	if ((ptr = static_push (arena, nbytes, alignment)) != NULL)
		return ptr;

	next_adress = (uintptr_t)(memb->block + memb->offset);
	padding = (-next_adress) & (alignment - 1);
	// = (alignment - (next_adress % alignment)) % alignment

	new_size = max (nbytes + padding, memb->size * 2);

	if ((new_block = ALLOC (sizeof (struct MemoryBlock) + new_size))
	    == NULL)
		return NULL;
	block_init (new_block, new_size);
	new_block->node.prev = &memb->node;
	arena->bottom = new_block;
	return static_push (arena, nbytes, alignment);
}

void *
Arena_push (struct T *arena, size_t nbytes, size_t alignment)
{
	assert (alignment != 0);
	assert (is_power_of_two (alignment));
	switch (arena->type) {
	case ARENA_DYNAMIC:
		return dynamic_push (arena, nbytes, alignment);
	case ARENA_STATIC:
		return static_push (arena, nbytes, alignment);
	default:
		return NULL;
	};
}

static void
static_clear (struct T *arena)
{
	arena->bottom->offset = 0;
}

/*
 * In dynamic we also relase memory when we clear it or stamp it
 */
static void
dynamic_clear (struct T *arena)
{
	struct Node *node = &arena->bottom->node;
	struct MemoryBlock *list;
	while (node->prev != NULL) {
		list = container_of (node, struct MemoryBlock, node);
		node = list->node.prev;
		FREE (list);
	}
	list = container_of (node, struct MemoryBlock, node);
	list->offset = 0;
}

void
Arena_clear (struct T *arena)
{
	switch (arena->type) {
	case ARENA_STATIC:
		static_clear (arena);
		break;
	case ARENA_DYNAMIC:
		dynamic_clear (arena);
		break;
	}
}

static inline ArenaIndex
encode (struct MemoryBlock *memb)
{
	return memb->offset ^ (uintptr_t)memb;
}

struct ArenaSnapshot
Arena_snapshot (struct T *arena)
{
	struct MemoryBlock *memb = arena->bottom;
	return (struct ArenaSnapshot){
		.arena = arena,
		.position = encode (memb),
		// what block did we start on, zebrist hash maybe?
	};
}

void
Arena_rollback (struct ArenaSnapshot snapshot)
{
	switch (snapshot.arena->type) {
	case ARENA_STATIC:
		break;
	case ARENA_DYNAMIC:
		break;
	default:
		break;
	}
}
