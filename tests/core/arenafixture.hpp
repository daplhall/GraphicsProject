#ifndef GUARD_MEMFIXTURE_H
#define GUARD_MEMFIXTURE_H

#include <gtest/gtest.h>
#include "core/arena.h"

class Arena256 : public ::testing::Test{
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
    


#endif //GUARD_MEMFIXTURE_H