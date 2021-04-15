/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-louis.boulet
** File description:
** ex06.c
*/

#include "list.h"
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "new.h"
#include "int.h"
#include "float.h"

int main(void)
{
    Object *list = new (List, 10, Float, 9.99f);
    Object *it = begin(list);
    Object *it_end = end(list);

    setitem(list, 2, 2.22f);
    setitem(list, 10, 10.10f);
    setitem(list, 3, 3.3f);
    setitem(list, 4, 4.4f);
    deleteitem(it_end, list, 10);
    insertitem(it_end, list, 9, 55.555);
    printf("array size: %zu\n", len(list));
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete(list);
    delete(it);
    delete(it_end);
}   