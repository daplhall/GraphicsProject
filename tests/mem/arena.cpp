#include "mem/arena.h"
#include "arenafixture.hpp"
#include "memspy.h"
#include <cstdlib>
#include <limits.h>

TEST (Arena, Create)
{
	Arena *arena;
	arena = Arena_create (256, ARENA_STATIC);
	ASSERT_TRUE (arena != NULL);
	Arena_release (arena);
}

TEST (Arena, ToMuchMemory)
{
	Arena *arena;
	arena = Arena_create (2024, ARENA_STATIC);
	ASSERT_TRUE (arena == NULL);
}

TEST_F (Arena256, PushSuccess)
{
	char *ptr;
	ptr = (char *)Arena_push (arena, 16 * sizeof (char), alignof (char));
	ASSERT_TRUE (ptr != NULL);
}

TEST_F (Arena256, PushSuccessClose)
{
	char *ptr
	    = (char *)Arena_push (arena, 256 * sizeof (char), alignof (char));
	ASSERT_TRUE (ptr != NULL);
}

TEST_F (Arena256, PushToMuch)
{
	char *ptr
	    = (char *)Arena_push (arena, 512 * sizeof (char), alignof (char));
	ASSERT_TRUE (ptr == NULL);
}

TEST_F (Arena256, PushToMuchTooClose)
{
	char *ptr
	    = (char *)Arena_push (arena, 257 * sizeof (char), alignof (char));
	ASSERT_TRUE (ptr == NULL);
}

TEST_F (Arena256, LinearAllocation)
{
	char *ref
	    = (char *)Arena_push (arena, 16 * sizeof (char), alignof (char));
	char *ptr
	    = (char *)Arena_push (arena, 16 * sizeof (char), alignof (char));
	ASSERT_TRUE ((ptr - ref) == 16);
}

TEST_F (Arena256, Alignment64)
{
	char *p = (char *)Arena_push (arena, 16 * sizeof (char), 64);
	ASSERT_TRUE ((uintptr_t)p % 64 == 0);
}

TEST_F (Arena256, Alignment32)
{
	char *p = (char *)Arena_push (arena, 16 * sizeof (char), 32);
	ASSERT_TRUE ((uintptr_t)p % 32 == 0);
}

TEST_F (Arena256, Alignment16)
{
	char *p = (char *)Arena_push (arena, 16 * sizeof (char), 16);
	ASSERT_TRUE ((uintptr_t)p % 16 == 0);
}

TEST_F (Arena256, Alignment4)
{
	char *p = (char *)Arena_push (arena, 16 * sizeof (char), 4);
	ASSERT_TRUE ((uintptr_t)p % 4 == 0);
}

TEST_F (Arena256, MultiplePush)
{
	char *p = (char *)Arena_push (arena, 16 * sizeof (char), 1);
	char *q = (char *)Arena_push (arena, sizeof (char), 1);
	ASSERT_TRUE (q - p == 16);
}

TEST_F (ArenaDynamic4, DynamicAllocate)
{
	char *q = (char *)Arena_push (arena, 4, 1);
	ASSERT_TRUE (q != NULL);
	char *p = (char *)Arena_push (arena, 4, 1);
	ASSERT_TRUE (p != NULL);
}

TEST_F (ArenaDynamic4, DynamicAllocateMultiple)
{
	char *q = (char *)Arena_push (arena, 4, 1);
	ASSERT_TRUE (q != NULL);
	for (int i = 0; i < 4; ++i) {
		char *p = (char *)Arena_push (arena, 4, 1);
		ASSERT_TRUE (p != NULL);
	}
}

TEST_F (ArenaDynamic4, AllocateMoreThanNormal)
{

	char *ptr = (char *)Arena_push (arena, 9, 1);
	struct mem_register reg = MemSpy_LastestAllocation ();
	ASSERT_TRUE (reg.amount == (ptr - (char *)reg.ptr) + 9 + 4);
}

/*
TEST_F(Arena256, SetPosDynamic){
    FAIL();
}
TEST_F(Arena256, SetPosDynamicToLarge){
    FAIL();
}

TEST_F(Arena256, SetPosDynamicNegative){
    FAIL();
}

TEST_F(Arena256, Clear){
    FAIL();
}
*/
