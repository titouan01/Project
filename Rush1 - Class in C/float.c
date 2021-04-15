/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-louis.boulet
** File description:
** float
*/

#include <stdio.h>
#include "float.h"
#include "new.h"
#define STR char *__attribute__((__cleanup__(destroy_str)))

void destroy_str(char **str);

typedef struct
{
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

Object *addition_Float(FloatClass *v1, FloatClass *v2)
{
    float result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x + v2->x;
    v3 = new (Float, result_x);
    return (v3);
}

Object *sub_Float(FloatClass *v1, FloatClass *v2)
{
    float result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x - v2->x;
    v3 = new (Float, result_x);
    return (v3);
}

char *float_str(FloatClass *this)
{
    STR res;
    char x[57];
    int size;

    sprintf(x, "%f", this->x);
    size = 13 + strlen(x);
    res = malloc(size);
    if (this == NULL)
        raise("Wrong int");
    snprintf(res, size, "<Float (%f)>", this->x);
    return (strdup(res));
}

Object *mult_Float(FloatClass *v1, FloatClass *v2)
{
    float result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x * v2->x;
    v3 = new (Float, result_x);
    return (v3);
}

Object *div_Float(FloatClass *v1, FloatClass *v2)
{
    float result_x = 0;
    Object *v3 = NULL;

    if (v2->x == 0)
        raise("Can't devide a number by 0");
    result_x = v1->x / v2->x;
    v3 = new (Float, result_x);
    return (v3);
}

bool Float_equal(FloatClass *v1, FloatClass *v2)
{
    return (v1->x == v2->x);
}

bool Float_superior(FloatClass *v1, FloatClass *v2)
{
    return (v1->x > v2->x);
}

bool Float_inferior(FloatClass *v1, FloatClass *v2)
{
    return (v1->x < v2->x);
}
// Create additional functions here

static const FloatClass _description = {
    {/* Class struct */
     .__size__ = sizeof(FloatClass),
     .__name__ = "Float",
     .__ctor__ = (ctor_t)&Float_ctor,
     .__dtor__ = NULL,
     .__str__ = (to_string_t)&float_str,
     .__add__ = (binary_operator_t)&addition_Float,
     .__sub__ = (binary_operator_t)&sub_Float, /* Implement this method for exercice 03 */
     .__mul__ = (binary_operator_t)&mult_Float,
     .__div__ = (binary_operator_t)&div_Float,
     .__eq__ = (binary_comparator_t)&Float_equal,
     .__gt__ = (binary_comparator_t)&Float_superior,
     .__lt__ = (binary_comparator_t)&Float_inferior},
    .x = 0};

const Class *Float = (const Class *)&_description;
