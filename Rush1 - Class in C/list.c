/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct
{
    Container base;
    Class *_type;
    size_t _size;
    linkedList_t *_list;
} ListClass;

typedef struct
{
    Iterator base;
    ListClass *_list;
    size_t _idx;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    linkedList_t *node = this->_list->_list;
    if (this->_idx >= this->_list->_size)
        raise("Out of range");
    for (size_t i = 0; i < this->_idx; i++) {
        node = node->next;
    }
    return(node->obj);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
}

static const ListIteratorClass ListIteratorDescr = {
    {
        /* Iterator struct */
        {
            /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = NULL,
    },
    ._list = NULL,
    ._idx = 0};
static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static void List_ctor(ListClass *this, va_list *args)
{
	linkedList_t *node = NULL;
    linkedList_t *prev_node = NULL;
    va_list arg_copy;

    this->_size = va_arg(*args, size_t);
	this->_type = va_arg(*args, Class *);
    this->_list = malloc(sizeof(linkedList_t));
    va_copy(arg_copy, *args);
    this->_list->obj = va_new(this->_type, args);
    this->_list->next = NULL;
    prev_node = this->_list;
	for (size_t i  = 1; i < this->_size; i++) {
        va_copy(*args, arg_copy);
        node = malloc(sizeof(linkedList_t));
        node->obj = va_new(this->_type, args);
        node->next = NULL;
        prev_node->next = node;
        prev_node = prev_node->next;
    }
}
 
static void List_dtor(ListClass *this)
{
    linkedList_t *next_node = this->_list->next;
    for (size_t i = 0; i < this->_size; i++) {
        free(this->_list->obj);
        free(this->_list);
        this->_list = next_node;
        if (this->_list != NULL)
            next_node = this->_list->next;
    }
}

static Iterator *List_begin(ListClass *this)
{
    return (new (ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new (ListIterator, this, this->_size));
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static void List_setitem(ListClass *this, ...)
{
    va_list list;
    size_t pos;
    linkedList_t *node = this->_list;

    va_start(list, this);
    pos = va_arg(list, size_t);
    if (pos > this->_size || pos == 0)
        raise("Out of range");
    for (size_t i = 1; i < pos; i++) {
        node = node->next;
    }
    free(node->obj);
    node->obj = va_new(this->_type, &list);
}

static void insert_item(linkedList_t *node, linkedList_t *inserted, int pos)
{
    if (pos == 1)
        inserted->next = node;
    else {
        inserted->next = node->next;
        node->next = inserted;
    }
}

static void List_insertitem(ListIteratorClass *it, ListClass *this, ...)
{
    va_list list;
    size_t pos;
    linkedList_t *node = this->_list;
    linkedList_t *inserted = malloc(sizeof(linkedList_t));

    va_start(list, this);
    pos = va_arg(list, size_t);
    if (pos > (this->_size + 1) || pos == 0)
        raise("Out of range");
    for (size_t i = 1; i < pos - 1; i++) {
        node = node->next;
    }
    inserted->obj = va_new(this->_type, &list);
    insert_item(node, inserted, pos);
    if (pos == 1)
        this->_list = inserted;
    this->_size += 1;
    it->_idx += 1;
}

static void del_item(linkedList_t *node)
{
    linkedList_t *hold_node = node;
    node = node->next;
    if(node->next == NULL) {
        free(node->obj);
        free(node);
        hold_node->next = NULL;
    } else {
        hold_node->next = node->next;
        free(node->obj);
        free(node);
    }
}

static void List_deleteitem(ListIteratorClass *it, ListClass *this, ...)
{
    va_list list;
    size_t pos;
    linkedList_t *node = this->_list;

    va_start(list, this);
    pos = va_arg(list, size_t);
    if (pos > this->_size || pos == 0)
        raise("Out of range");
    for (size_t i = 1; i < pos - 1; i++) {
        node = node->next;
    }
    del_item(node);
    this->_size -= 1;
    it->_idx -= 1;
}

static const ListClass _descr = {
    {
        /* Container struct */
        {
            /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = NULL,
        .__setitem__ = (setitem_t)&List_setitem,
        .__insertitem__ = (insertitem_t)&List_insertitem,
        .__deleteitem__ = (deleteitem_t)&List_deleteitem,
    },
    ._type = NULL,
    ._size = 0,
    ._list = NULL};

const Class *List = (const Class *)&_descr;