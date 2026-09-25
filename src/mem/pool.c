#include "mem/pool.h"
#include "mem/arena.h"
#include <assert.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stddef.h>

#define T	  MemPool
#define EMPTYPOOL NULL

struct _MemPool {
	struct _MemPool *next;
};

struct _MemPool *
partition (char *mem, size_t n, size_t full_size)
{
	assert (n > 0);
	char *cursor = mem;
	struct _MemPool *current = NULL, *prev = EMPTYPOOL;
	for (size_t i = 0; i < n; ++i) {
		current = (struct _MemPool *)(cursor + i * full_size);

		*current = (struct _MemPool){
			.next = prev,
		};
		prev = current;
	}
	return current;
}

T
MemPool_create (Arena *arena, size_t size, size_t nbytes, size_t align)
{
	assert (nbytes >= sizeof (T) && "Chunk size is too small");

	size_t n = size / nbytes;
	char *pool;
	pool = Arena_push (arena, n * nbytes, align);
	if (pool == NULL)
		return NULL;
	return partition (pool, n, nbytes);
}

void *
MemPool_populate (T *pool)
{
	if (*pool == EMPTYPOOL) {
		return NULL;
	}
	T out = (*pool);
	(*pool) = (*pool)->next;
	return out;
}
void
MemPool_depopulate (T *pool, void *ptr)
{
	struct _MemPool *block = ptr;
	*block = (struct _MemPool){
		.next = *pool,
	};
	*pool = block;
}

size_t
MemPool_sizeof (void)
{
	return sizeof (T);
}

bool
MemPool_IsEmpty (T *pool)
{
	return *pool == EMPTYPOOL;
}
