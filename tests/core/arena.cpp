#include <cstdlib>
#include <gtest/gtest.h>
#include <core/arena.h>

TEST(Arena, Create){
    size_t capacity = 256;
    Arena *arena = Arena_create(capacity);
    ASSERT_TRUE(arena != NULL);
    Arena_release(arena);
}

