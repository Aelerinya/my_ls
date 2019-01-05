/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Error management
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

void *my_raise(char *error, char *file)
{
    if (file == NULL)
        perror(error);
    else {
        my_put_error(error);
        perror(file);
    }
    return NULL;
}

void *memory_error(void)
{
    my_put_error("Could not allocate more memory.\n");
    return NULL;
}
