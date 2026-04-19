#ifndef GUARD_STACKARENA_H
#define GUARD_STACKARENA_H

#ifdef __cplusplus
extern "C" {
#endif 
#include <core/arena.h>
#include <stddef.h>
#include <stdalign.h>

#define T Arena

typedef struct _Arena T;

enum Arena_type {
    ARENA_STATIC,
    ARENA_DYNMAIC
};

enum Arena_error{
    ARENA_OK,
    ARENA_BAD_ALLOC,
    ARENA_BAD_TYPE,
};


T * Arena_create(size_t capacity, enum Arena_type type);
void * Arena_push(T* arena, size_t nbytes, size_t alignment);
void Arena_release(T *arena);
enum Arena_error Arena_GetError(T *arena);
size_t Arena_occupied(T *arena);
    
#undef T
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
