/*
 * TODO Checkpoints
 * TODO Checkpoints Dynamcic -- Deallocate from offset
 */
#include "foundation.h"
#include "intrusivelist.h"
#include "mem/arena.h"
#include "mem/mem.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#define T _Arena

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
	size_t offset;
	char *block;
};

struct T {
	struct MemoryBlock *bottom;
	size_t size;
	enum Arena_type type;
};

static void
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
	size_t additional = nbytes + padding;
	size_t remaning = memb->size - memb->offset;

	if (additional > remaning)
		return NULL;
	memb->offset += additional;
	return (void *)(next_adress + padding);
}

static void *
dynamic_push (struct T *arena, size_t nbytes, size_t alignment)
{

	struct MemoryBlock *memb = arena->bottom;
	uintptr_t next_adress = (uintptr_t)(memb->block + memb->offset);
	uintptr_t padding = (-next_adress) & (alignment - 1);
	// = (alignment - (next_adress % alignment)) % alignment
	size_t additional = nbytes + padding;
	size_t remaning = memb->size - memb->offset;

	if (additional > remaning) {
		size_t new_size = max (additional, memb->size * 2);
		struct MemoryBlock *new_block;

		if ((new_block = ALLOC (sizeof (struct MemoryBlock) + new_size))
		    == NULL)
			return NULL;
		block_init (new_block, new_size);
		new_block->node.prev = &memb->node;
		arena->bottom = new_block;

		return static_push (arena, nbytes, alignment);
	} else {
		memb->offset += nbytes + padding;
		return (void *)(next_adress + padding);
	}
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

/**
enum Arena_type {
    ARENA_STATIC,
    ARENA_DYNMAIC
};

enum Arena_error{
    ARENA_OK,
    ARENA_BAD_ALLOC,
    ARENA_BAD_TYPE,
    ARENA_BAD_POSITION,
};

void * Arena_push(T* arena, size_t nbytes, size_t alignment);
void Arena_pop(T* arena, size_t nbytes);
enum Arena_error Arena_setpos(T* arena, size_t pos);
void Arena_clear(T* arena);
enum Arena_error Arena_GetError(T *arena);
// Scratch Arena
P ArenaTemp_create(T* arena);
void ArenaTemp_release(P *temp_arena);
**/
