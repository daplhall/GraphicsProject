#include "core/mem.h"
#include <assert.h>
#include <stdlib.h>
#include <threads.h>

thread_local static enum Mem_error error = MEM_OK;

static char const *error_messages[]
    = { "No error occured", "Pointer input is null", "Could not Allocate" };

enum Mem_error
Mem_GetError (void)
{
	return error;
}

char const *
Mem_ErrorMessage (enum Mem_error error_code)
{
	return error_messages[error_code];
}

void *
Mem_alloc (size_t capacity, char const *file, int line)
{
	char *p;
	assert (capacity > 0);
	p = malloc (capacity);
	if (p == NULL)
		error = MEM_BAD_ALLOC;
	else
		error = MEM_OK;
	return p;
}

void *
Mem_calloc (size_t count, size_t nbytes, char const *file, int line)
{
	void *p;
	assert (count > 0);
	assert (nbytes > 0);

	p = calloc (count, nbytes);
	if (p == NULL)
		error = MEM_BAD_ALLOC;
	else
		error = MEM_OK;
	return p;
}

void *
Mem_realloc (void *to_realloc, size_t new_size, char const *file, int line)
{
	void *p;
	assert (new_size > 0);
	if (to_realloc == NULL) {
		error = MEM_BAD_POINTER;
		return NULL;
	}
	p = realloc (to_realloc, new_size);
	if (p == NULL)
		error = MEM_BAD_ALLOC;
	else
		error = MEM_OK;
	return p;
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