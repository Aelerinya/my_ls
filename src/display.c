/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Display the file name lists
*/

#include <stdlib.h>
#include "prototypes.h"

void display_directory(char *dir_path, int header)
{
    char **files;

    files = read_file_names(dir_path);
    bubble_sort(files, &my_strcmp);
    if (header) {
        my_putstr(dir_path);
        my_putstr(":\n");
    }
    display_list(files);
}

void display_list(char **list)
{
    for (int i = 0; list[i] != NULL; i++) {
        my_putstr(list[i]);
        my_putstr("\n");
    }
}
