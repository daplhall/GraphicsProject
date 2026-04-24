#ifndef GUARD_MEMSPY_H
#define GUARD_MEMSPY_H

#ifdef __cplusplus
extern "C" {
#endif 
#include <core/mem.h>
    
struct mem_register {
	void *ptr;
	char const *file;
	int line;
};

struct mem_register MemSpy_LastestAllocation();

    
#ifdef __cplusplus
}
#endif 
#endif //GUARD_STACKARENA_H
