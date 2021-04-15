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
#include "point.h"
#include "vertex.h"
#include "array.h"

int main(void)
{
    printf("EX02...............................................................");
    Object *point = new (Point, 42, -42);
    Object *vertex = new (Vertex, 0, 1, 2);

    printf("point = %s\n", str(point));
    printf("vertex = %s\n", str(vertex));

    delete (point);
    delete (vertex);

    printf("\n\n\nEX03...............................................................\n\n\n");

    Object *p1 = new (Point, 12, 13);
    Object *p2 = new (Point, 2, 2);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

    Object *v1 = new(Vertex, 1957747793, 1957747793, 1957747793);
    Object *v2 = new(Vertex, 1957747793, 1957747793, 1957747793);

    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));

    printf("\n\n\nEX04...............................................................\n\n\n");

    Object *int_obj_1 = new (Int, 1);
    Object *int_obj_2 = new (Int, 2);

    printf("%s * %s = %s\n", str(int_obj_1), str(int_obj_2), str(multiplication(int_obj_1, int_obj_2)));
    printf("%s / %s = %s\n", str(int_obj_1), str(int_obj_2), str(division(int_obj_1, int_obj_2)));

    Object *float_obj_1 = new (Float, 3.0f);
    Object *float_obj_2 = new (Float, 1.5f);

    printf("%s * %s = %s\n", str(float_obj_1), str(float_obj_2), str(multiplication(float_obj_1, float_obj_2)));
    printf("%s / %s = %s\n", str(float_obj_1), str(float_obj_2), str(division(float_obj_1, float_obj_2)));
    
    printf("\n\n\nEX05...............................................................\n\n\n");

    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete (array);

    printf("\n\n\nEX06...............................................................\n\n\n");

    Object *list = new (List, 10, Float, 9.99f);
    it = begin(list);
    it_end = end(list);

    setitem(list, 2, 2.22f);
    setitem(list, 10, 10.10f);
    setitem(list, 3, 3.3f);
    setitem(list, 4, 4.4f);
    deleteitem(it_end, list, 10);
    insertitem(it_end, list, 9, 55.555);
    printf("array size: %zu\n", len(list));
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete(list);
    delete(it);
    delete(it_end);
}   