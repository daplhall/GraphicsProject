#include "arena/arena.h"
#include "arena_internal.h"
#include <stdint.h>

#define T	    _Arena
#define ArenaOffset size_t

struct _ArenaSnapshot {
	size_t id;
};

static inline ArenaIndex
encode (size_t id)
{
	return id += 1;
}

struct _ArenaSnapshot *
Arena_snapshot (struct T *arena)
{
	return NULL;
}

void
Arena_rollback (struct T *arena, struct _ArenaSnapshot *snapshot)
{
	encode (snapshot->id);
}
