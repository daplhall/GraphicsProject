#include "arena/arena.h"
#include "arena_internal.h"
#include "mem/mem.h"
#include "shared/foundation.h"
#include <stdint.h>

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
	struct Node *node = &arena->bottom->node;
	while (node != NULL) {
		struct MemoryBlock *block;
		size_t block_beginning;

		block = container_of (node, struct MemoryBlock, node);
		block_beginning = arena->used - block->offset;
		if (block_beginning <= snapshot) {
			block->offset = snapshot - block_beginning;
			arena->used = snapshot;
			arena->bottom = block;
			return;
		}

		node = node->prev;
		arena->used -= block->offset;
		block->offset = 0;
		FREE (block);
	}
}

/*
 * block -> block -> block
 *   S			^
 *
 *
 *
 */
