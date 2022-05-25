#include "vector.h"

int vector_init(struct vector *vector, size_t capacity)
{
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(capacity * sizeof(VECTOR_TYPE));

    if (vector->data == NULL)
        return -1;

    return 0;
}

int vector_resize(struct vector *vector, size_t new_size)
{
    vector->data = realloc(vector->data, new_size);
    if (vector->data == NULL)
        return -1;

    vector->capacity = new_size;

    if (vector->size > new_size)
        vector->size = new_size;

    return 0;
}

int vector_append(struct vector *vector, void *value)
{
    if (vector->size == vector->capacity)
        vector_resize(vector, vector->capacity * 2);

    vector->data[vector->size] = value;
    vector->size++;

    return 0;
}

VECTOR_TYPE vector_get(struct vector *vector, size_t position)
{
    if (position >= vector->size)
        return (void*) -1;

    return vector->data[position];
}

void vector_free(struct vector *vector)
{
    free(vector->data);
}
