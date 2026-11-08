#ifndef GUARD_DICTIONARYFIXTURE_HPP
#define GUARD_DICTIONARYFIXTURE_HPP

#include "collections/hashmap.h"
#include "mem/arena/arena.h"
#include <gtest/gtest.h>

class Hashmap256B : public ::testing::Test
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

#endif // GUARD_DICTIONARYFIXTURE_HPP
