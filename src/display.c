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
    char **list;
    file_t *files;

    list = read_file_names(dir_path);
    bubble_sort(list, &my_strcmp);
    files = convert_file_list(dir_path, list);
    if (header) {
        my_putstr(dir_path);
        my_putstr(":\n");
    }
    for (int i = 0; files[i].name != NULL; i++) {
        display_file(files + i);
    }
}

void display_file(file_t *file)
{
    my_putstr(file->name);
    my_putstr("\n");
}
