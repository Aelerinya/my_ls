/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Sorting functions
*/

#include <stdlib.h>
#include "prototypes.h"

void sort_files(file_t *files, char *options)
{
    if (options['t'])
        bubble_sort(files, &timesort);
    else
        bubble_sort(files, &my_alphasort);
    if (options['r'])
        reverse_list(files);
}

void reverse_list(file_t *files)
{
    int len;
    int middle;
    file_t tmp;

    for (len = 0; files[len].name != NULL; len++);
    middle = len / 2;
    for (int i = 0; i < middle; i++) {
        tmp = files[i];
        files[i] = files[len - i - 1];
        files[len - i - 1] = tmp;
    }
}

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
    while (!is_sorted(files, sorter)) {
        for (int i = 0; files[i + 1].name != NULL; i++) {
            if (sorter(files + i, files + i + 1) > 0) {
                tmp = files[i];
                files[i] = files[i + 1];
                files[i + 1] = tmp;
            }
        }
    }
}
