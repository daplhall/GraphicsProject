
#ifndef GUARD_TESTPOOLFIXTURE_HPP
#define GUARD_TESTPOOLFIXTURE_HPP
#include <gtest/gtest.h>
#include "core/arena.h"
#include "core/pool.h"

class Pool16Arena16Capacity : public ::testing::Test{
    public:
        Arena *arena;
        MemPool *pool;
    protected:
        void SetUp(){
            arena = Arena_create(16*Arena_sizeof()+64, ARENA_STATIC);
            pool = MemPool_create(arena ,16 , Arena_sizeof() + 4);
        }
        
        void TearDown(){
            Arena_release(arena);
        }
};


#endif // GUARD_TESTMEMFIXTURES