/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Sorting functions
*/

#include <stdlib.h>
#include "prototypes.h"

int is_sorted(file_t *files, int (*sorter)(file_t *, file_t *))
{
    if (files[0].name == NULL || files[1].name == NULL)
        return (1);
    for (int i = 0; files[i + 1].name != NULL; i++)
        if (sorter(files + i, files + i + 1) > 0)
            return (0);
    return (1);
}

void bubble_sort(file_t *files, int (*sorter)(file_t *, file_t *))
{
    file_t tmp;

    if (files[0].name == NULL || files[1].name == NULL)
        return;
    while(!is_sorted(files, sorter)) {
        for (int i = 0; files[i + 1].name != NULL; i++) {
            if (sorter(files + i, files + i + 1) > 0) {
                tmp = files[i];
                files[i] = files[i + 1];
                files[i + 1] = tmp;
            }
        }
    }
}
