#ifndef GUARD_STACKARENA_H
#define GUARD_STACKARENA_H

#ifdef __cplusplus
extern "C" {
#endif 
#include <mem/arena.h>
#include <stddef.h>
#include <stdalign.h>

#define T Arena
#define B ArenaAllocator
#define P ArenaPartition

typedef struct _Arena T;
typedef struct _Arena B;
typedef struct _Arena P;

enum Arena_type {
    ARENA_STATIC,
    ARENA_DYNMAIC
};

enum Arena_error{
    ARENA_OK,
    ARENA_BAD_ALLOC,
    ARENA_BAD_TYPE,
};


void * Arena_push(T* arena, size_t nbytes, size_t alignment);
void Arena_pop(T* arena, size_t nbytes);
void Arena_clear(T* arena);
enum Arena_error Arena_GetError(T *arena);
    
B * ArenaAllocator_create(size_t reserve, enum Arena_type type);
void ArenaAllocator_release(B *arena);
size_t ArenaAllocator_sizeof (void);

P * Arena_partition(T* arena, size_t reserve);
size_t ArenaPartition_sizeof (void);



#undef T
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
