
#ifndef GUARD_TESTPOOLFIXTURE_HPP
#define GUARD_TESTPOOLFIXTURE_HPP
#include <gtest/gtest.h>
#include "core/arena.h"
#include "core/pool.h"

class Pool4x16 : public ::testing::Test{
    public:
        Arena *arena;
        MemPool pool;
    protected:
        void SetUp(){
            arena = Arena_create(64, ARENA_STATIC);
            pool = MemPool_create(arena ,64 , 16, 1);
        }
        
        void TearDown(){
            Arena_release(arena);
        }
};

class Pool1x16 : public ::testing::Test{
    public:
        Arena *arena;
        MemPool pool;
    protected:
        void SetUp(){
            arena = Arena_create(16, ARENA_STATIC);
            pool = MemPool_create(arena ,16 , 16, 1);
        }
        
        void TearDown(){
            Arena_release(arena);
        }
};


#endif // GUARD_TESTMEMFIXTURES