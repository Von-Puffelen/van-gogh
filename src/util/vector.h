#ifndef _VECTOR_H__
#define _VECTOR_H__

#include <stdlib.h>

#define VECTOR_TYPE void*

struct vector {
    void **data;
    size_t capacity;
    size_t size;
};

int vector_init(struct vector *vector, size_t capacity);
int vector_resize(struct vector *vector, size_t new_size);
int vector_append(struct vector *vector, void *value);

VECTOR_TYPE vector_get(struct vector *vector, size_t position);

void vector_free(struct vector *vector);

#endif /* _VECTOR_H__ */
