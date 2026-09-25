#ifndef GUARD_DICTIONARYFIXTURE_HPP
#define GUARD_DICTIONARYFIXTURE_HPP

#include <gtest/gtest.h>
#include "mem/arena.h"
#include "collections/hashmap.h"

class Hashmap256B : public ::testing::Test{
    public:
        Arena *arena;

    protected:

        void SetUp(){
            arena = Arena_create(256, ARENA_STATIC);
        }
        
        void TearDown(){
            Arena_release(arena);
        }
};

#endif // GUARD_DICTIONARYFIXTURE_HPP