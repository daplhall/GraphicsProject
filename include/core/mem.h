#ifndef GUARD_GRAPHICSPROJECTMEM_H
#define GUARD_GRAPHICSPROJECTMEM_H
#ifdef __cplusplus
extern "C" {
#endif 
#include <stddef.h>

enum Mem_error {
	MEM_OK = 0,
	MEM_BAD_POINTER,
	MEM_BAD_CAPACITY,
	MEM_BAD_NBYTES,
	MEM_BAD_COUNT,
	MEM_BAD_SIZE,
};

#define ALLOC(capacity) Mem_alloc((capacity), __FILE__, __LINE__)
#define CALLOC(count, nbytes) Mem_calloc((count), (nbytes), __FILE__, __LINE__)
#define REALLOC(ptr, size) Mem_realloc((ptr), (size), __FILE__, __LINE__)
#define FREE(ptr) Mem_free((ptr),__FILE__, __LINE__)
#define NEW(ptr)

void *Mem_alloc(size_t capacity, char const* file, int line);
void *Mem_calloc(size_t count, size_t nbytes, char const* file, int line);
void *Mem_realloc(void *to_realloc, size_t new_size, char const *file, int line);
int Mem_free(void *ptr, char const* file, int line);

enum Mem_error Mem_GetError();
char const * Mem_ErrorMessage(enum Mem_error error);

#ifdef __cplusplus
}
#endif 
#endif // GUARD_GRAPHICSPROJECTMEM_H
