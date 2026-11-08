#ifndef GUARD_ALIGNMENT_H
#define GUARD_ALIGNMENT_H
#include <stddef.h>
#include <stdint.h>

uintptr_t alignment_forward (uintptr_t ptr_to_align, size_t align);
#endif // GUARD_ALIGNMENT_H