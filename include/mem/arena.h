#ifndef GUARD_STACKARENA_H
#define GUARD_STACKARENA_H

#ifdef __cplusplus
extern "C" {
#endif
#include <mem/arena.h>
#include <stdalign.h>
#include <stddef.h>

#define T Arena
#define P ArenaTemp

typedef struct _Arena T;
typedef struct {
	T *const arena;
	size_t loc;
} P;

enum Arena_type {
	ARENA_STATIC,
	ARENA_DYNAMIC,
};

enum Arena_error {
	ARENA_OK,
	ARENA_BAD_ALLOC,
	ARENA_BAD_TYPE,
	ARENA_BAD_POSITION,
};

void *Arena_push (T *arena, size_t nbytes, size_t alignment);
void Arena_clear (T *arena);
T *Arena_create (size_t reserve, enum Arena_type type);
void Arena_release (T *arena);

#undef T
#undef P
#ifdef __cplusplus
}
#endif
#endif // GUARD_STACKARENA_H
