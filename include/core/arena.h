#ifndef GUARD_STACKARENA_H
#define GUARD_STACKARENA_H

#ifdef __cplusplus
extern "C" {
#endif 
#include <core/arena.h>
#include <stddef.h>


#define T Arena

typedef struct _Arena T;

T * Arena_create(size_t capacity);
void Arena_release(T *arena);

    
#undef T
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
