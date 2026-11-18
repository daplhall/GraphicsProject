#include "arena/arena.h"
#include "shared/intrusivelist.h"

#define T _Arena

struct MemoryBlock {
	struct Node node;
	size_t size;
	size_t offset;
	char *block;
};

struct T {
	struct MemoryBlock *bottom;
	size_t used;
	enum Arena_type type;
};
