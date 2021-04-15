/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-louis.boulet
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"
#define STR char *__attribute__((__cleanup__(destroy_str)))

void destroy_str(char **str);

typedef struct
{
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

char *int_str(IntClass *this)
{
    STR res;
    char x[12];
    int size;

    sprintf(x, "%d", this->x);
    size = 11 + strlen(x);
    res = malloc(size);
    if (this == NULL)
        raise("Wrong int");
    snprintf(res, size, "<Int (%d)>", this->x);
    return (strdup(res));
}

Object *addition_Int(IntClass *v1, IntClass *v2)
{
    int result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x + v2->x;
    v3 = new (Int, result_x);
    return (v3);
}

Object *sub_Int(IntClass *v1, IntClass *v2)
{
    int result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x - v2->x;
    v3 = new (Int, result_x);
    return (v3);
}

Object *mult_Int(IntClass *v1, IntClass *v2)
{
    int result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x * v2->x;
    v3 = new (Int, result_x);
    return (v3);
}

Object *div_Int(IntClass *v1, IntClass *v2)
{
    int result_x = 0;
    Object *v3 = NULL;

    if (v2->x == 0)
        raise("Can't devide a number by 0");
    result_x = v1->x / v2->x;
    v3 = new (Int, result_x);
    return (v3);
}

bool Int_equal(IntClass *v1, IntClass *v2)
{
    return (v1->x == v2->x);
}

bool Int_superior(IntClass *v1, IntClass *v2)
{
    return (v1->x > v2->x);
}

bool Int_inferior(IntClass *v1, IntClass *v2)
{
    return (v1->x < v2->x);
}
// Create additional functions here

static const IntClass _description = {
    {/* Class struct */
     .__size__ = sizeof(IntClass),
     .__name__ = "Int",
     .__ctor__ = (ctor_t)&Int_ctor,
     .__dtor__ = NULL,
     .__str__ = (to_string_t)&int_str,
     .__add__ = (binary_operator_t)&addition_Int,
     .__sub__ = (binary_operator_t)&sub_Int, /* Implement this method for exercice 03 */
     .__mul__ = (binary_operator_t)&mult_Int,
     .__div__ = (binary_operator_t)&div_Int,
     .__eq__ = (binary_comparator_t)&Int_equal,
     .__gt__ = (binary_comparator_t)&Int_superior,
     .__lt__ = (binary_comparator_t)&Int_inferior},
    .x = 0};

const Class *Int = (const Class *)&_description;
