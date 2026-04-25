#include "core/pool.h"
#include "core/arena.h"
#include <assert.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>

#define T MemPool
#define R PoolBlock

struct _MemPool {
	int i;
};

T *
MemPool_create (Arena *arena, size_t n, size_t size)
{
	T *pool = Arena_push (arena, n * size, alignof (T));

	return pool;
}

// Control to allocated N blocks directly to the free list, that we we cna
// say we want N block to be next to eahcother void
// PoolPartition_populate(size_t count) This could maybe pack the data
// different ly ie |chunk1|chunk2|chunk3|mem1|mem2|mem3| rather than
// |chunk1|mem1|chunk2|mem2|chunk3|mem3| Then we essentially have 2 cache
// lines one of chunk and one of mem This needs to be tested