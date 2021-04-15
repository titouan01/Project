/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-louis.boulet
** File description:
** char
*/

#include <stdio.h>
#include "char.h"
#include "new.h"
#define STR char *__attribute__((__cleanup__(destroy_str)))

void destroy_str(char **str);

typedef struct
{
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

char *char_str(CharClass *this)
{
    STR res;
    char x;
    int size;

    size = 13;
    res = malloc(size);
    if (this == NULL)
        raise("Wrong char");
    snprintf(res, size, "<Char (%c)>", this->x);
    return (strdup(res));
}

Object *addition_Char(CharClass *v1, CharClass *v2)
{
    char result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x + v2->x;
    v3 = new (Char, result_x);
    return (v3);
}

Object *sub_Char(CharClass *v1, CharClass *v2)
{
    char result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x - v2->x;
    v3 = new (Char, result_x);
    return (v3);
}

Object *mult_Char(CharClass *v1, CharClass *v2)
{
    char result_x = 0;
    Object *v3 = NULL;

    result_x = v1->x * v2->x;
    v3 = new (Char, result_x);
    return (v3);
}

Object *div_Char(CharClass *v1, CharClass *v2)
{
    char result_x = 0;
    Object *v3 = NULL;

    if (v2->x == 0)
        raise("Can't devide a number by 0");
    result_x = v1->x / v2->x;
    v3 = new (Char, result_x);
    return (v3);
}

bool Char_equal(CharClass *v1, CharClass *v2)
{
    return (v1->x == v2->x);
}

bool Char_superior(CharClass *v1, CharClass *v2)
{
    return (v1->x > v2->x);
}

bool Char_inferior(CharClass *v1, CharClass *v2)
{
    return (v1->x < v2->x);
}
// Create additional functions here

static const CharClass _description = {
    {/* Class struct */
     .__size__ = sizeof(CharClass),
     .__name__ = "Char",
     .__ctor__ = (ctor_t)&Char_ctor,
     .__dtor__ = NULL,
     .__str__ = (to_string_t)&char_str,
     .__add__ = (binary_operator_t)&addition_Char,
     .__sub__ = (binary_operator_t)&sub_Char, /* Implement this method for exercice 03 */
     .__mul__ = (binary_operator_t)&mult_Char,
     .__div__ = (binary_operator_t)&div_Char,
     .__eq__ = (binary_comparator_t)&Char_equal,
     .__gt__ = (binary_comparator_t)&Char_superior,
     .__lt__ = (binary_comparator_t)&Char_inferior},
    .x = 0};

const Class *Char = (const Class *)&_description;