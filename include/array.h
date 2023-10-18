#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define T array_t
typedef struct T *T;

#define array_create(type) _array_create(sizeof(type), 1)
extern T _array_create(size_t data_size, int capacity);
extern void array_destroy(T array);
extern void array_clean(T array);
extern T array_copy(T array);
extern int array_empty(const T array);
extern int array_size(const T array);
extern size_t array_data_size(const T array);
extern void *array_get(const T array, int index);
extern void array_put(T array, int index, const void *data);
extern void array_push_back(T array, const void *data);
extern void array_pop_back(T array);
extern void array_remove(T array, int index);
extern void array_traversal(T array, void func(void *));

#undef T
#endif
