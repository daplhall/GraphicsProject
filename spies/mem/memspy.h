#ifndef GUARD_MEMSPY_H
#define GUARD_MEMSPY_H

#ifdef __cplusplus
extern "C" {
#endif 
#include <mem/mem.h>
    
struct mem_register {
	void *ptr;
	size_t amount;
	char const *file;
	int line;
};

struct mem_register MemSpy_LastestAllocation();

    
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
