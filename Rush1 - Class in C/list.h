/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush1-louis.boulet
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

// lib

#include "container.h"

// struct

typedef struct linkedList_s
{
    Object *obj;
    struct linkedList_s *next;
}linkedList_t;

extern const Class *List;

// function

#endif /* !LIST_H_ */
