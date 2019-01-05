/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Display the file name lists
*/

#include <stdlib.h>
#include "prototypes.h"

int display_directory(char *dir_path, int header)
{
    char **list;
    file_t *files;

    if ((list = read_file_names(dir_path)) == NULL)
        return (1);
    bubble_sort(list, &my_strcmp);
    if ((files = convert_file_list(dir_path, list)) == NULL)
        return (1);
    if (header) {
        my_putstr(dir_path);
        my_putstr(":\n");
    }
    for (int i = 0; files[i].name != NULL; i++)
        display_file(files + i);
    return (0);
}

void display_file(file_t *file)
{
    my_putstr(file->name);
    my_putstr("\n");
}
