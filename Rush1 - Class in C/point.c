/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#define STR char *__attribute__((__cleanup__(destroy_str)))

void destroy_str(char **str);

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static char *Point_str(PointClass *this)
{
    STR buffer;
    char x[12];
    char y[12];
    int size;

    sprintf(x, "%d", this->x);
    sprintf(y, "%d", this->y);
    size = 13 + strlen(x) + strlen(y);
    buffer = malloc(size);
    if (this == NULL)
        raise("Class does not exist");
    snprintf(buffer, size, "<Point (%d, %d)>", this->x, this->y);
    return (strdup(buffer));
}

Object *addition_point(PointClass *v1, PointClass *v2)
{
    int result_x = 0;
    int result_y = 0;
    Object *v3 = NULL;

    result_x = v1->x + v2->x;
    result_y = v1->y + v2->y;
    v3 = new (Point, result_x, result_y);
    return (v3);
}

Object *sub_point(PointClass *v1, PointClass *v2)
{
    int result_x = 0;
    int result_y = 0;
    Object *v3 = NULL;

    result_x = v1->x - v2->x;
    result_y = v1->y - v2->y;
    v3 = new (Point, result_x, result_y);
    return (v3);
}
// Create additional functions here

static const PointClass _description = {
    {/* Class struct */
     .__size__ = sizeof(PointClass),
     .__name__ = "Point",
     .__ctor__ = (ctor_t)&Point_ctor,
     .__dtor__ = NULL,
     .__str__ = (to_string_t)&Point_str,
     .__add__ = (binary_operator_t)&addition_point,
     .__sub__ = (binary_operator_t)&sub_point, /* Implement this method for exercice 03 */
     .__mul__ = NULL,
     .__div__ = NULL,
     .__eq__ = NULL,
     .__gt__ = NULL,
     .__lt__ = NULL},
    .x = 0,
    .y = 0};

const Class *Point = (const Class *)&_description;
