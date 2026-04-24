#include "linear_arena.c"

size_t
ArenaSpy_GetBlockSize ()
{
	return sizeof (struct block);
}
