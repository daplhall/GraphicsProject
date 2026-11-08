#ifndef GUARD_COLLECTIONS_HASHMAP_H
#define GUARD_COLLECTIONS_HASHMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mem/arena/arena.h"

#define Hashmap T
typedef struct T T;

T *Hashmap_create (Arena *arena);

#ifdef __cplusplus
}
#endif
#endif // GUARD_COLLECTIONS_HASHMAP_H
