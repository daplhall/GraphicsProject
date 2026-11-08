#ifndef GUARD_TESTMEMFIXTURES_HPP
#define GUARD_TESTMEMFIXTURES_HPP
#include "mem/mem.h"
#include <gtest/gtest.h>

class Alloc : public ::testing::Test
{
      public:
	int *allocated;

      protected:
	void
	SetUp ()
	{
		allocated = (int *)ALLOC (sizeof (int));
	}
	void
	TearDown ()
	{
		FREE (allocated);
	}
};

class Calloc : public ::testing::Test
{
      public:
	int *allocated;

      protected:
	void
	SetUp ()
	{
		allocated = (int *)CALLOC (1, sizeof (int));
	}
	void
	TearDown ()
	{
		FREE (allocated);
	}
};
class Realloc : public ::testing::Test
{
      public:
	int *allocated;

      protected:
	void
	SetUp ()
	{
		allocated = (int *)ALLOC (sizeof (int));
	}
	void
	TearDown ()
	{
		FREE (allocated);
	}
};

#endif // GUARD_TESTMEMFIXTURES_HPP