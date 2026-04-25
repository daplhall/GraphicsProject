#include <gtest/gtest.h>
#include <wchar.h>
#include "poolfixture.hpp"

TEST_F(Pool16Arena16Capacity, Allocate){
    ASSERT_TRUE(pool != NULL);
}
/*
PoolPartiion_create(Arena,  Arena_sizeof() + 64, 6)
Arena *ptr = PoolPartiion_populate(AreanPool)
Arena_etch(ptr, capacity) -> Partitions a given block of memory into an arena with a given capacity
*/