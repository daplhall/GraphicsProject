#ifndef GUARD_MEMFIXTURE_H
#define GUARD_MEMFIXTURE_H

#include <gtest/gtest.h>
#include "mem/arena.h"

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

class ArenaDynamic4: public ::testing::Test  {
    public:
        Arena *arena;
    protected:
         void SetUp(){
            arena = Arena_create(4, ARENA_DYNMAIC);
         }
        
        void TearDown(){
            Arena_release(arena);
        }
        
};
    


#endif //GUARD_MEMFIXTURE_H