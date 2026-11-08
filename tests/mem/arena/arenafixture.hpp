#ifndef GUARD_MEMFIXTURE_H
#define GUARD_MEMFIXTURE_H

#include "mem/arena/arena.h"
#include <gtest/gtest.h>

class Arena256 : public ::testing::Test
{
      public:
	Arena *arena;

      protected:
	void
	SetUp ()
	{
		arena = Arena_create (256, ARENA_STATIC);
	}

	void
	TearDown ()
	{
		Arena_release (arena);
	}
};

class ArenaDynamic4 : public ::testing::Test
{
      public:
	Arena *arena;

      protected:
	void
	SetUp ()
	{
		arena = Arena_create (4, ARENA_DYNAMIC);
	}

	void
	TearDown ()
	{
		Arena_release (arena);
	}
};

#endif // GUARD_MEMFIXTURE_H
