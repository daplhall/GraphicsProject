#include "core/mem.h"
#include <assert.h>
#include <stdlib.h>
#include <threads.h>

thread_local static enum Mem_error error = MEM_OK;
static char const *error_messages[] = {
	"No error occured",
	"Pointer input is null",
};

enum Mem_error
Mem_GetError ()
{
	return error;
}

char const *
Mem_ErrorMessage (enum Mem_error error)
{
	return error_messages[error];
}

void *
Mem_alloc (size_t capacity, char const *file, int line)
{
	assert (capacity > 0);
	error = MEM_OK;
	return malloc (capacity);
}

void *
Mem_calloc (size_t count, size_t nbytes, char const *file, int line)
{
	assert (count > 0);
	assert (nbytes > 0);

	error = MEM_OK;
	return calloc (count, nbytes);
}

void *
Mem_realloc (void *to_realloc, size_t new_size, char const *file, int line)
{
	assert (new_size > 0);
	if (to_realloc == NULL) {
		error = MEM_BAD_POINTER;
		return NULL;
	}
	error = MEM_OK;
	return realloc (to_realloc, new_size);
}

int
Mem_free (void *ptr, char const *file, int line)
{
	if (ptr == NULL) {
		error = MEM_BAD_POINTER;
		return MEM_BAD_POINTER;
	}
	free (ptr);
	error = MEM_OK;
	return error;
}