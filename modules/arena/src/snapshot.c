#include "arena/arena.h"
#include "arena_internal.h"
#include "mem/mem.h"
#include "shared/foundation.h"
#include <assert.h>

#define T	    _Arena
#define ArenaOffset size_t

ArenaSnapshot
Arena_snapshot (struct T *arena)
{
	return arena->used;
}

void
Arena_rollback (struct T *arena, ArenaSnapshot snapshot)
{
	assert (arena != NULL);
	assert (snapshot <= arena->used);

	struct Node *node = &arena->bottom->node;
	while (node != NULL) {
		struct MemoryBlock *block;
		size_t block_start;

		block = container_of (node, struct MemoryBlock, node);
		block_start = arena->used - block->offset;
		if (block_start <= snapshot) {
			block->offset = snapshot - block_start;
			arena->used = snapshot;
			arena->bottom = block;
			return;
		}

		node = node->prev;

		arena->used -= block->offset;
		FREE (block);
	}
}
