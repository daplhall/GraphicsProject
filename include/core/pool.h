#ifndef GUARD_ARENAPOOL_H
#define GUARD_ARENAPOOL_H
#ifdef __cplusplus
extern "C" {
#endif 
#include <stdbool.h>
#include "core/arena.h"

#define T MemPool
typedef struct _MemPool *T;

T MemPool_create (Arena *arena, size_t size, size_t nbytes, size_t align);
void *MemPool_populate (T *pool);
void MemPool_depopulate(T *pool, void *ptr);
size_t MemPool_sizeof (void);
bool MemPool_IsEmpty (T *pool);

#undef T
#ifdef __cplusplus
}
#endif 
#endif //GUARD_ARENAPOOL_H
