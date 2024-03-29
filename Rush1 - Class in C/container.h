/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 05
*/

#ifndef CONTAINER_H
#define CONTAINER_H

#include "object.h"
#include "iterator.h"
#include "raise.h"

typedef struct Container_s Container;

typedef Iterator *(*iter_t)(Container *this);
typedef size_t (*len_t)(Container *this);
typedef Object *(*getitem_t)(Container *this, ...);
typedef void (*setitem_t)(Container *this, ...);
typedef void (*insertitem_t)(Container *this, ...);
typedef void (*deleteitem_t)(Container *this, ...);

struct Container_s
{
    Class base;
    len_t __len__;
    iter_t __begin__;
    iter_t __end__;
    getitem_t __getitem__;
    setitem_t __setitem__;
    insertitem_t __insertitem__;
    deleteitem_t __deleteitem__;
};

#define len(c) ((Container *)c)->__len__(c)
#define begin(c) ((Container *)c)->__begin__(c)
#define end(c) ((Container *)c)->__end__(c)
#define getitem(c, ...) ((Container *)c)->__getitem__(c, __VA_ARGS__)
#define setitem(c, ...) ((Container *)c)->__setitem__(c, __VA_ARGS__)
#define insertitem(i, c, ...) ((Container *)c)->__insertitem__(i, c, __VA_ARGS__)
#define deleteitem(i, c, ...) ((Container *)c)->__deleteitem__(i, c, __VA_ARGS__)

#endif
