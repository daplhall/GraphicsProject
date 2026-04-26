#include "mem/pool.h"
#include <gtest/gtest.h>
#include "poolfixture.hpp"

TEST_F(Pool4x16, Allocate){
    ASSERT_TRUE(pool != NULL);
}

TEST_F(Pool4x16, Populate){
    assert(MemPool_populate(&pool) != NULL);
}

TEST_F(Pool4x16, PopulateMultiple){
    char *p = (char *)MemPool_populate(&pool);
    char *q = (char *)MemPool_populate(&pool);
    *p = 'a';
    *q = 'b';
    ASSERT_TRUE(p != q);
    ASSERT_TRUE(p != NULL);
    ASSERT_TRUE(q != NULL);
    ASSERT_TRUE(*p == 'a');
    ASSERT_TRUE(*q == 'b');
}

TEST_F(Pool4x16, Deallocate){
    char *a = (char *)MemPool_populate(&pool);
    MemPool_depopulate(&pool, (void *)a);
    ASSERT_TRUE(!MemPool_IsEmpty(&pool));
}

/*
PoolPartiion_create(Arena,  Arena_sizeof() + 64, 6)
Arena *ptr = PoolPartiion_populate(AreanPool)
Arena_etch(ptr, capacity) -> Partitions a given block of memory into an arena with a given capacity
*/