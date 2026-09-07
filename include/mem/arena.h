#ifndef GUARD_STACKARENA_H
#define GUARD_STACKARENA_H

#ifdef __cplusplus
extern "C" {
#endif 
#include <mem/arena.h>
#include <stddef.h>
#include <stdalign.h>

#define T Arena
#define P ArenaTemp

typedef struct _Arena T;
typedef struct 
{
    T *const arena;
    size_t loc;
} P;

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
T * Arena_create(size_t reserve, enum Arena_type type);
void Arena_release(T *arena);
// Scratch Arena
P ArenaTemp_create(T* arena);
void ArenaTemp_release(P *temp_arena);


#undef T
#undef P
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
