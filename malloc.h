/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stddef.h>
#include <unistd.h>

typedef struct data
{
    size_t struct_size;
    size_t size;
    void *adress;
    char isfree;
    struct data *next;
    struct data *prev;

} data_t;

// malloc
void *Mmalloc(size_t size);
void *Mcalloc(size_t nmemb, size_t size);
void Mfree(void *ptr);
void *Mrealloc(void *ptr, size_t size);
void *Mreallocarray(void *ptr, size_t nmemb, size_t size);

//list
data_t *init_list(size_t size);
data_t *init_node(data_t *data, size_t size);
data_t *put_back(data_t *data, size_t size);
data_t *pop_back(data_t *struc);




#endif /* !MALLOC_H_ */
