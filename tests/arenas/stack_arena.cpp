#include <gtest/gtest.h>
#include <arenas/stack_arena.h>

TEST(StackArena, invoke){
    size_t capacity = 256;
    StackArena arena = Arena_StackAlloc(capacity);
    ASSERT_TRUE(arena != NULL);
    Arena_Release(arena);
}
