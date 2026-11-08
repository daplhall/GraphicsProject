#ifndef GUARD_SRC_INTRUSIVELIST_H
#define GUARD_SRC_INTRUSIVELIST_H
#ifdef __cplusplus
extern "C" {
#endif

struct Node {
	struct Node *next;
	struct Node *prev;
};

#ifdef __cplusplus
}
#endif
#endif // GUARD_SRC_INTRUSIVELIST_H
