#include "alignment.h"

uintptr_t
alignment_forward (uintptr_t ptr_to_align, size_t align)
{
	return (ptr_to_align + align - 1) & ~(align - 1);
}