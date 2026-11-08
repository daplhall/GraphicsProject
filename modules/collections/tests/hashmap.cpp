#include "hashmapfixture.hpp"
#include "gtest/gtest.h"

TEST_F (Hashmap256B, Create)
{
	Hashmap *map = Hashmap_create (arena);
	ASSERT_TRUE (map != NULL);
}

TEST_F (Hashmap256B, AssignStr) { GTEST_SKIP_ ("To be implemented"); }

TEST_F (Hashmap256B, FetchStr) { GTEST_SKIP_ ("To be implemented"); }

TEST_F (Hashmap256B, Distribution) { GTEST_SKIP_ ("To be implemented"); }

TEST_F (Hashmap256B, PopElement) { GTEST_SKIP_ ("To be implemented"); };

TEST_F (Hashmap256B, OverwriteValue) { GTEST_SKIP_ ("To be implemented"); }

TEST_F (Hashmap256B, OutOfMemory) { GTEST_SKIP_ ("To be implemented"); }