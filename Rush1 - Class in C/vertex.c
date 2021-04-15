/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"
#define STR char *__attribute__((__cleanup__(destroy_str)))

void destroy_str(char **str);

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

// Create additional functions here

char *Vertex_str(VertexClass *this)
{
    STR res;
    char x[12];
    char y[12];
    char z[12];
    int size;

    sprintf(x, "%d", this->x);
    sprintf(y, "%d", this->y);
    sprintf(z, "%d", this->z);
    size = 18 + strlen(x) + strlen(y) + strlen(z);
    res = malloc(size);
    if (this == NULL)
        raise("Wrong vertex");
    snprintf(res, size, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (strdup(res));
}

Object *addition_vertex(VertexClass *v1, VertexClass *v2)
{
    int result_x = 0;
    int result_z = 0;
    int result_y = 0;
    Object *v3 = NULL;

    result_x = v1->x + v2->x;
    result_y = v1->y + v2->y;
    result_z = v1->z + v2->z;

    v3 = new (Vertex, result_x, result_y, result_z);
    return (v3);
}

Object *sub_vertex(VertexClass *v1, VertexClass *v2)
{
    int result_x = 0;
    int result_z = 0;
    int result_y = 0;
    Object *v3 = NULL;

    result_x = v1->x - v2->x;
    result_y = v1->y - v2->y;
    result_z = v1->z - v2->z;

    v3 = new (Vertex, result_x, result_y, result_z);
    return (v3);
}

static const VertexClass _description = {
    {/* Class struct */
     .__size__ = sizeof(VertexClass),
     .__name__ = "Vertex",
     .__ctor__ = (ctor_t)&vertex_ctor,
     .__dtor__ = NULL,
     .__add__ = (binary_operator_t)&addition_vertex,
     .__str__ = (to_string_t)&Vertex_str,
     .__sub__ = (binary_operator_t)&sub_vertex, /* Implement this method for exercice 03 */
     .__mul__ = NULL,
     .__div__ = NULL,
     .__eq__ = NULL,
     .__gt__ = NULL,
     .__lt__ = NULL},
    .x = 0,
    .y = 0,
    .z = 0};

const Class *Vertex = (const Class *)&_description;
