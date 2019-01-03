/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Sorting functions
*/

#include <stdlib.h>
#include "prototypes.h"

int my_strcmp(char *s1, char *s2)
{
    int pos = 0;

    while (s1[pos] != '\0' && s2[pos] != '\0' && s1[pos] == s2[pos])
        pos++;
    return (s1[pos] - s2[pos]);
}

int is_sorted(char **list, int (*sorter)(char *, char *))
{
    if (list[0] == NULL || list[1] == NULL)
        return (1);
    for (int i = 0; list[i + 1] != NULL; i++)
        if (sorter(list[i], list[i + 1]) > 0)
            return (0);
    return (1);
}

void bubble_sort(char **list, int (*sorter)(char *, char*))
{
    char *tmp;

    if (list[0] == NULL || list[1] == NULL)
        return;
    while(!is_sorted(list, sorter)) {
        for (int i = 0; list[i + 1] != NULL; i++) {
            if (sorter(list[i], list[i + 1]) > 0) {
                tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
            }
        }
    }
}
