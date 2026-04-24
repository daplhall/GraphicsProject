#include "memspy.h"
#include <stdlib.h>

#define MAX	  526
#define REGISTERS 2048

static enum Mem_error error = MEM_OK;
static struct mem_register lastest_alloc = { 0 };

void *
Mem_alloc (size_t capacity, char const *file, int line)
{
	if (capacity > MAX) {
		error = MEM_BAD_ALLOC;
		return NULL;
	}
	error = MEM_OK;
	void *ptr = malloc (capacity);
	lastest_alloc = (struct mem_register){
		.ptr = ptr,
		.amount = capacity,
		.file = file,
		.line = line,
	};
	return ptr;
}

void *
Mem_calloc (size_t count, size_t nbytes, char const *file, int line)
{
	if (count + nbytes > MAX) {
		error = MEM_BAD_ALLOC;
		return NULL;
	}
	error = MEM_OK;

	void *ptr = calloc (count, nbytes);
	lastest_alloc = (struct mem_register){
		.ptr = ptr,
		.amount = count * nbytes,
		.file = file,
		.line = line,
	};
	return ptr;
}

void *
Mem_realloc (void *to_realloc, size_t new_size, char const *file, int line)
{
	if (new_size > MAX) {
		error = MEM_BAD_ALLOC;
		return NULL;
	}
	error = MEM_OK;
	void *ptr = realloc (to_realloc, new_size);
	lastest_alloc = (struct mem_register){
		.ptr = ptr,
		.amount = new_size,
		.file = file,
		line = line,
	};
	return ptr;
}

int
Mem_free (void *ptr, char const *file, int line)
{
	if (ptr == NULL)
		return MEM_BAD_POINTER;
	free (ptr);
	lastest_alloc = (struct mem_register){ 0 };
	return MEM_OK;
}

struct mem_register
MemSpy_LastestAllocation ()
{
	return lastest_alloc;
}