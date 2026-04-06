#include "core/mem.h"
#include <stdlib.h>

#define MAX 526

static enum Mem_error error = MEM_OK;

void *
Mem_alloc (size_t capacity, char const *file, int line)
{
	if (capacity > MAX) {
		error = MEM_BAD_ALLOC;
		return NULL;
	}
	error = MEM_OK;
	return malloc (capacity);
}

void *
Mem_calloc (size_t count, size_t nbytes, char const *file, int line)
{
	if (count + nbytes > MAX) {
		error = MEM_BAD_ALLOC;
		return NULL;
	}
	error = MEM_OK;
	return calloc (count, nbytes);
}

void *
Mem_realloc (void *to_realloc, size_t new_size, char const *file, int line)
{
	if (new_size > MAX) {
		error = MEM_BAD_ALLOC;
		return NULL;
	}
	error = MEM_OK;
	return realloc (to_realloc, new_size);
}

int
Mem_free (void *ptr, char const *file, int line)
{
	if (ptr == NULL)
		return MEM_BAD_POINTER;
	free (ptr);
	return MEM_OK;
}
