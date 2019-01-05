/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Sort files by modification time
*/

#include "prototypes.h"

int timesort(file_t *f1, file_t *f2)
{
    if (f1->stat->st_mtime > f2->stat->st_mtime)
        return (-1);
    else if (f1->stat->st_mtime < f2->stat->st_mtime)
        return (1);
    else
        return (0);
}
