/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** list
*/

#include "malloc.h"
#include <unistd.h>

data_t *init_list(size_t size)
{
    data_t *ret = sbrk(sizeof(data_t) + size);

    ret->struct_size = sizeof(data_t);
    ret->size = size;
    ret->adress = sbrk(0) + ret->struct_size;
    ret->isfree = 0;
    ret->next = NULL;
    ret->prev = NULL;
    return (ret);
}

data_t *init_node(data_t *data, size_t size)
{
    data_t *tmp = data;

    tmp->next = sbrk(sizeof(data_t) + size);
    tmp = tmp->next;
    tmp->struct_size = sizeof(data_t);
    tmp->size = size;
    tmp->adress = sbrk(0) + tmp->struct_size;
    tmp->isfree = 0;
    tmp->next = NULL;
    tmp->prev = data;
    return (tmp);
}

data_t *re_node(data_t *data, size_t size)
{
    data_t *tmp = data;

    tmp->struct_size = sizeof(data_t);
    tmp->size = size;
    tmp->isfree = 0;
    return (tmp);
}

data_t *put_back(data_t *data, size_t size)
{
    data_t *tmp = data;
    short isfree = 0;

    if (tmp->next == NULL) {
        tmp->next = init_node(tmp, size);
    } else {
        while (tmp->next != NULL) {
            if (tmp->isfree == 1 && tmp->size > size) {
                isfree = 1;
                break;
            }
            tmp = tmp->next;
        }
        if (isfree == 1)
            tmp = re_node(tmp, size);
        else
            tmp->next = init_node(tmp, size);
    }
    return (data);
}

data_t *pop_back(data_t *struc)
{
    data_t *tmp = struc;

    if (tmp->next == NULL) {
        tmp = NULL;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp = NULL;
    }
    return (struc);
}
