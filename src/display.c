/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Display the file name lists
*/

#include <stdlib.h>
#include "prototypes.h"

void display_list(char **list)
{
    for (int i = 0; list[i] != NULL; i++) {
        my_putstr(list[i]);
        my_putstr("\n");
    }
}
