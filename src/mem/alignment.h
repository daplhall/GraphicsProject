#ifndef GUARD_ALIGNMENT_H
#define GUARD_ALIGNMENT_H
#include <stdint.h>
#include <stddef.h>

uintptr_t alignment_forward (uintptr_t ptr_to_align, size_t align);
#endif //GUARD_ALIGNMENT_H