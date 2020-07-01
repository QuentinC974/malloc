/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#include "malloc.h"
#include <string.h>
#include <stdio.h>



static data_t *data = NULL;

void *malloc(size_t size)
{
    write(1, "malloc\n", 7);
    data_t *tmp;

    if (size <= 0)
        return (NULL);
    if (data == NULL)
        data = init_list(size);
    else
        data = put_back(data, size);
    tmp = data;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->adress);
}

void *calloc(size_t nmemb, size_t size)
{
    write(1, "calloc\n", 7);
    data_t *tmp;

    if (size * nmemb <= 0)
        return (NULL);
    if (data == NULL)
        data = init_list(size * nmemb);
    else
        data = put_back(data, size * nmemb);
    tmp = data;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->adress);
}

void free(void *ptr)
{
    write(1, "free\n", 5);
    // data_t *tmp = data;
    // while (tmp->adress != ptr && tmp->next != NULL) {
    //     printf("coucou2\n");
    //     tmp = tmp->next;
    // }
    // if (tmp != NULL)
    //     tmp->isfree = 1;
}

void *realloc(void *ptr, size_t size)
{
    write(1, "realloc\n", 8);
    void *ret;
    data_t *tmp = data;
    while (tmp->adress != ptr && tmp->next != NULL) {
        printf("coucou\n");
        tmp = tmp->next;
    }
    if (tmp != NULL) {
        if (tmp->size >= size) {
            ret = malloc(size);
            memcpy(ret, ptr, tmp->size);
            free(ptr);
            return (ret);
        }
    }
    free(ptr);
    return (malloc(size));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    write(1, "realloca\n", 9);
    free(ptr);
    return (malloc(size * nmemb));
}

