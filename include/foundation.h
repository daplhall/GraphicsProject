#ifndef GUARD_INCLUDE_FOUNDATION_H
#define GUARD_INCLUDE_FOUNDATION_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Container of as used in the linux kernel
 *
 */
#if defined(__GNUC__) || defined(__clang__) || defined(BASE_CONTAINER_OF)
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)((char *)__mptr - offsetof(type,member));})
#else
#define container_of(ptr, type, member)(type *) ((type *)((char *)__mptr - offsetof(type,member)))
#endif
#ifdef __cplusplus
}
#endif
#endif //GUARD_INCLUDE_FOUNDATION_H
