/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 05
*/

#include "new.h"
#include "raise.h"
#define STR char *__attribute__((__cleanup__(destroy_str)))

void destroy_str(char **str);

void destroy_str(char **str)
{
    if (*str)
        free(*str);
}

Object *new (const Class *Player, ...)
{
    Object *obj;
    va_list list;

    va_start(list, Player);
    obj = va_new(Player, &list);
    va_end(list);
    return (obj);
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *obj;
    if (class == NULL)
        raise("Class does not exist");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Out of memory");
    obj = memcpy(obj, class, class->__size__);
    if (obj->__ctor__)
        obj->__ctor__(obj, ap);
    return (obj);
}

void delete (Object *ptr)
{
    Class *test = (Class *)ptr;
    if (test->__dtor__)
        test->__dtor__((Class *)ptr);
    free(ptr);
}
