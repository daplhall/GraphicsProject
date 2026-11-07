/*
 * TODO Checkpoints
 * TODO Checkpoints Dynamcic -- Deallocate from offset
 * TODO Alignment
 */
#include "foundation.h"
#include "intrusivelist.h"
#include "mem/arena.h"
#include "mem/mem.h"
#include <assert.h>
#include <stddef.h>

#define T _Arena

struct MemoryList {
	struct Node node;
	size_t size;
	size_t offset;
	char *block;
};

struct T {
	struct MemoryList *bottom;
	size_t size;
	enum Arena_type type;
};

static void
list_init (struct MemoryList *list, size_t reserve)
{
	*list = (struct MemoryList){ .node = (struct Node){ .prev = NULL,
							    .next = NULL },
				     .size = reserve,
				     .offset = 0,
				     .block = (char *)(list + 1) };
}

struct T *
Arena_create (size_t reserve, enum Arena_type type)
{
	struct T *arena = CALLOC (1, sizeof (struct T));
	struct MemoryList *list = ALLOC (sizeof (struct MemoryList) + reserve);

	list_init (list, reserve);
	*arena = (struct T){ .bottom = list, .size = reserve, .type = type };

	return arena;
}

void
Arena_release (struct T *arena)
{
	struct Node *node = &arena->bottom->node;
	while (node != NULL) {
		struct MemoryList *list;
		list = container_of (node, struct MemoryList, node);
		node = list->node.prev;
		FREE (list);
	}
	FREE (arena);
}

static void *
upsert_list (struct MemoryList *list, size_t new_offset)
{
	char *block = list->block;
	block += list->offset;
	list->offset = new_offset;
	return (void *)(block);
}

static void *
static_push (struct T *arena, size_t nbytes, size_t alignment)
{
	struct MemoryList *list = arena->bottom;
	size_t new_offset = list->offset + nbytes;
	if (list->size < new_offset)
		return NULL;
	return upsert_list (list, new_offset);
}

static void *
dynamic_push (struct T *arena, size_t nbytes, size_t alignment)
{
	struct MemoryList *list = arena->bottom, *new = NULL;
	size_t new_offset = list->offset + nbytes;
	if (list->size < new_offset) {
		new = ALLOC (sizeof (struct MemoryList) + nbytes + list->size);
		list_init (new, nbytes + list->size);

		new->node.prev = &list->node;
		arena->bottom = new;
		list = new;
	}
	return upsert_list (list, new_offset);
}

void *
Arena_push (struct T *arena, size_t nbytes, size_t alignment)
{
	if (arena->type == ARENA_DYNAMIC)
		return dynamic_push (arena, nbytes, alignment);

	else
		return static_push (arena, nbytes, alignment);
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
