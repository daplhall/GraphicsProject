#include "core/mem.h"
#include <cassert>
#include <gtest/gtest.h>
#include "memfixture.hpp"


TEST_F(Alloc, Alloc){
    ASSERT_TRUE(allocated != NULL);
}

TEST_F(Alloc, FreeNull){
    ASSERT_TRUE(FREE(NULL) == MEM_BAD_POINTER);
}

TEST_F(Calloc, Alloc){
    ASSERT_TRUE(allocated != NULL) ;
    ASSERT_TRUE(*allocated == 0);
}

TEST_F(Realloc, Alloc){
    int *remember = allocated;
    allocated = (int *)REALLOC(allocated, 1*sizeof(*allocated));
    ASSERT_TRUE(allocated != NULL);
}

TEST_F(Realloc, NullInput){
    int *a = (int *)REALLOC(NULL, 1*sizeof(*allocated));
    ASSERT_TRUE(a == NULL);
    ASSERT_TRUE(Mem_GetError() == MEM_BAD_POINTER);
}