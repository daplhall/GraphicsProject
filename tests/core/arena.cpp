#include <cstdlib>
#include <gtest/gtest.h>
#include <core/arena.h>
#include "arenafixture.hpp"

TEST(Arena, Create){
    Arena *arena;
    arena = Arena_create(256, ARENA_STATIC);
    ASSERT_TRUE(arena != NULL);
    Arena_release(arena);
}

TEST(Arena, ToMuchMemory){
    Arena *arena;
    arena = Arena_create(2024, ARENA_STATIC);
    ASSERT_TRUE(arena == NULL);
}

TEST_F(Arena256, PushSuccess){
    char *ptr;
    ptr = (char*)Arena_push(arena, 16*sizeof(char), alignof(char));
    ASSERT_TRUE(ptr != NULL);
    ASSERT_TRUE(Arena_GetError(arena) == ARENA_OK);
}

TEST_F(Arena256, PushSuccessClose){
    char *ptr = (char*) Arena_push(arena, 256*sizeof(char), alignof(char));
    ASSERT_TRUE(ptr != NULL);
    ASSERT_TRUE(Arena_GetError(arena) == ARENA_OK);
}

TEST_F(Arena256, PushToMuch){
    char *ptr = (char*) Arena_push(arena, 512*sizeof(char), alignof(char));     
    ASSERT_TRUE(ptr == NULL);
    ASSERT_TRUE(Arena_GetError(arena) == ARENA_BAD_ALLOC);
}

TEST_F(Arena256, PushToMuchTooClose){
    char *ptr = (char*) Arena_push(arena, 257*sizeof(char), alignof(char));     
    ASSERT_TRUE(ptr == NULL);
    ASSERT_TRUE(Arena_GetError(arena) == ARENA_BAD_ALLOC);
}

TEST_F(Arena256, GetPos){
    Arena_push(arena, 16*sizeof(char), alignof(char));
    ASSERT_TRUE(Arena_occupied(arena) == 16);
}

TEST_F(Arena256, Alignment64){
    char *p = (char *)Arena_push(arena, 16*sizeof(char), 64);
    ASSERT_TRUE((uintptr_t)p%64 == 0);
}

TEST_F(Arena256, Alignment32){
    char *p = (char *)Arena_push(arena, 16*sizeof(char), 32);
    ASSERT_TRUE((uintptr_t)p%32 == 0);
}

TEST_F(Arena256, Alignment16){
    char *p = (char *)Arena_push(arena, 16*sizeof(char), 16);
    ASSERT_TRUE((uintptr_t)p%16 == 0);
}

TEST_F(Arena256, Alignment4){
    char *p = (char *)Arena_push(arena, 16*sizeof(char), 4);
    ASSERT_TRUE((uintptr_t)p%4 == 0);
}

TEST_F(Arena256, MultiplePush){
    char *p = (char *)Arena_push(arena, 16*sizeof(char), 4);
    char *q = (char *)Arena_push(arena, sizeof(char), 4);
    ASSERT_TRUE(q-p == 16);
}

TEST_F(ArenaDynamic4, DynamicAllocate){
    Arena_push(arena, 4, 1);
    char *p = (char *)Arena_push(arena, 4, 1);
    ASSERT_TRUE(p != NULL);
    ASSERT_TRUE(Arena_GetError(arena) == ARENA_OK);
}

TEST_F(ArenaDynamic4, DynamicAllocateMultiple){
    Arena_push(arena, 4, 1);
    for (int i = 0; i < 4; ++i){
        char *p = (char *)Arena_push(arena, 4, 1);
        ASSERT_TRUE(p != NULL);
    }
    ASSERT_TRUE(Arena_GetError(arena) == ARENA_OK);
}