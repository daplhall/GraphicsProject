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
