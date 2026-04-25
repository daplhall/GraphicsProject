#ifndef GUARD_ARENAPOOL_H
#define GUARD_ARENAPOOL_H
#ifdef __cplusplus
extern "C" {
#endif 
#include "core/arena.h"

#define T MemPool
typedef struct _MemPool T;

T *MemPool_create (Arena *arena, size_t n, size_t size);

#undef T
#ifdef __cplusplus
}
#endif 
#endif //GUARD_ARENAPOOL_H