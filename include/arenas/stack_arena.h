#ifndef GUARD_STACKARENA_H
#define GUARD_STACKARENA_H

#ifdef __cplusplus
extern "C" {
#include <cstddef>
#else 
#include <stddef.h>
#endif 
#include <arenas/arena.h>


#define T StackArena

typedef struct _StackArena * T;

T Arena_StackAlloc(size_t capacity);

    
#undef T
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
