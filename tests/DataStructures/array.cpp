#include <gtest/gtest.h>
#include <cstddef>
#include "DataStructures/arrays/int.h"

TEST (DynamicArray, IntCreate) {
    size_t capacity = 30;
    struct Array_int arr = Array_int_create(capacity);
    ASSERT_TRUE(arr.base.capacity == capacity);
    Array_int_dispose(arr);
}

TEST (DynamicArray, IntSetGet) {
    ArrayError error = ARRAY_UNKOWN;
    size_t capacity = 30;
    int x = 0;
    struct Array_int arr = Array_int_create(capacity);
    if ((error = Array_int_set(arr, 0, 42)) == ARRAY_FAILURE) {
        FAIL();
    }
    if ((error = Array_int_get(arr, 0, &x)) == ARRAY_FAILURE){
        FAIL();
    }
    ASSERT_TRUE(x == 42);
    if ((error = Array_int_dispose(arr)) == ARRAY_FAILURE){
        FAIL();
    }
}

/*
TEST (DynamicArray, IntAllocateWith) {
    size_t capacity = 30;
    struct IntArray arr = ARRAY_CREATE_WITH(Allocator, capacity);
    
    ARRAY_DISPOSE(arr)
}*/