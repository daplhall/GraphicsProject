#ifndef GUARD_ARRAY_H
#define GUARD_ARRAY_H

#ifdef __cplusplus
extern "C" {
    #include <cstddef>
    #include <cstdlib>
#else 
    #include <stddef.h>
    #include <stdlib.h>
#endif

#define T_HEADER\
        struct Array_HEAD base
    
#define DECLARE_ARRAY_NEW_TYPE(type)\
    struct Array##_##type{\
        T_HEADER;\
        type *items;\
    }

#define DECLARE_ARRAY_CREATE(type)\
    struct Array_##type Array_##type##_create(size_t capacity)

#define DECLARE_ARRAY_DISPOSE(type)\
    ArrayError Array_##type##_dispose(struct Array_##type array)

#define DECLARE_ARRAY_GETTERS(type)\
    ArrayError Array_##type##_get(struct Array_##type arr, size_t index, type *dest)

#define DECLARE_ARRAY_SETTERS(type)\
    ArrayError Array_##type##_set(struct Array_##type arr, size_t index, type value)


#define DECLARE_ARRAY(type)\
    DECLARE_ARRAY_NEW_TYPE(type);\
    DECLARE_ARRAY_CREATE(type);\
    DECLARE_ARRAY_DISPOSE(type);\
    DECLARE_ARRAY_GETTERS(type);\
    DECLARE_ARRAY_SETTERS(type);



#define DEFINITION_ARRAY_CREATE(type)\
    DECLARE_ARRAY_CREATE(type){\
        struct Array_##type array;\
        array.items = (type *)malloc(capacity*sizeof(type *));\
        array.base.capacity = capacity;\
        array.base.count = 0;\
        return array;\
    }

#define DEFINITION_ARRAY_DISPOSE(type)\
    DECLARE_ARRAY_DISPOSE(type){\
        free(array.items); \
        array.base.capacity = 0;\
        array.base.count = 0;\
        return ARRAY_SUCCESS;\
    }

#define DEFINITION_ARRAY_SETTERS(type)\
    DECLARE_ARRAY_SETTERS(type)\
    {\
        if (arr.base.capacity < arr.base.count) {   \
            return ARRAY_FAILURE; \
        }\
        arr.items[index] = value;\
        arr.base.count++;\
        return ARRAY_SUCCESS;\
    }

#define DEFINITION_ARRAY_GETTERS(type)\
    DECLARE_ARRAY_GETTERS(type)\
    {\
        *dest = arr.items[index];\
        return ARRAY_SUCCESS;\
    }


#define DEFINITONS_ARRAY(type)\
    DEFINITION_ARRAY_CREATE(type)\
    DEFINITION_ARRAY_DISPOSE(type)\
    DEFINITION_ARRAY_GETTERS(type)\
    DEFINITION_ARRAY_SETTERS(type)\

typedef enum {
    ARRAY_FAILURE=0,
    ARRAY_SUCCESS,
    ARRAY_UNKOWN
} ArrayError;


struct Array_HEAD {
    size_t capacity;
    size_t count;
};

#undef T
#undef T_error 
#undef T_HEAD  

#ifdef __cplusplus
}
#endif
#endif // GUARD_ARRAY_H