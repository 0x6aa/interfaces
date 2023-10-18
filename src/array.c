#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "array.h"

#define T array_t

#define ARRAY_GROWTH_RATE 2

/* Define a struct for dynamic array. */
struct T
{
    void *memory;
    int capacity;
    int size;
    size_t data_size;
};

static int array_resize(T array)
{
    void *temp;
    int new_capacity;

    assert(array);

    // Allocate new memory
    new_capacity = ARRAY_GROWTH_RATE * array->capacity;
    temp = malloc(new_capacity * array->data_size);

    if (!temp)
    {
        return -1;
    }

    // Copying memory
    memcpy(temp, array->memory, array->data_size * array->capacity);
    free(array->memory);

    array->capacity = new_capacity;
    array->memory = temp;

    return 0;
}

T _array_create(size_t data_size, int capacity)
{
    T array;

    assert(data_size > 0 && data_size <= INT_MAX);
    if ((array = (T)malloc(sizeof(struct T))) == NULL)
    {
        return NULL;
    }

    array->memory = malloc(data_size * capacity);
    assert(array->memory);

    array->size = 0;
    array->capacity = capacity;
    array->data_size = data_size;

    return array;
}

void array_destroy(T array)
{
    assert(array);

    free(array->memory);
    free(array);
}

void array_clean(T array)
{
    assert(array);

    array->size = 0;
}

T array_copy(const T array)
{
    T copy;

    assert(array);
    copy = _array_create(array->data_size, array->size);
    assert(copy);

    memcpy(copy->memory, array->memory, array->size * array->data_size);
    copy->size = array->size;
    return copy;
}

int array_size(const T array)
{
    assert(array);

    return array->size;
}

int array_empty(const T array)
{
    assert(array);

    return array->size == 0;
}

size_t array_data_size(const T array)
{
    assert(array);

    return array->data_size;
}

void *array_get(const T array, int index)
{
    assert(array);
    assert(index >= 0 && index < array->size);

    return array->memory + index * array->data_size;
}

void array_put(T array, int index, const void *data)
{
    assert(array);
    assert(index >= 0 && index < array->size);
    assert(data);

    memcpy(array->memory + index * array->data_size, data, array->data_size);
}

void array_push_back(T array, const void *data)
{
    int ret;

    assert(array);
    assert(data);

    if (array->size == array->capacity)
    {
        ret = array_resize(array);
        assert(ret == 0);
    }

    array->size++;
    array_put(array, array->size - 1, data);
}

void array_pop_back(T array)
{
    assert(array);
    assert(array->size > 0);

    array->size--;
}

void array_remove(T array, int index)
{
    assert(array);
    assert(index >= 0 && index < array->size);

    memcpy(array->memory + index * array->data_size,
           (array->memory) + (index + 1) * array->data_size,
           ((array->size) - (index + 1)) * array->data_size);
    array->size--;
}

void array_traversal(T array, void func(void *)) {
    assert(array);

    for(int i = 0; i < array->size; i++) {
        func(array->memory + i * array->data_size);
    }
}
