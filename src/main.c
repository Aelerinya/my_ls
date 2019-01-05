/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** main function
*/

#include <stdio.h>
#include "prototypes.h"

int main(int ac, char **av)
{
    char *options = get_options(ac, av);
    char **list = parse_arguments(ac, av);
    file_t *files;

    if (options == NULL || list == NULL)
        return (84);
    if (list[0] == NULL) {
        display_directory(".", 0);
        return 0;
    }
    bubble_sort(list, &my_strcmp);
    if (files = convert_file_list(NULL, list))
        return (84);
    if (separate_files_and_directory(files))
        return (84);
    return (0);
}

int separate_files_and_directory(file_t *files)
{
    int is_there_regular_files = 0;

    for(int i = 0; files[i].name != NULL; i++) {
        if (S_ISREG(files[i].stat->st_mode)) {
            display_file(files + i);
            is_there_regular_files = 1;
        }
    }
    my_putstr(is_there_regular_files ? "\n" : "");
    for(int i = 0; files[i].name != NULL; i++) {
        if (S_ISDIR(files[i].stat->st_mode)) {
            my_putstr(i != 0 ? "\n" : "");
            if (display_directory(files[i].name, (files[1].name != NULL)))
                return (1);
        }
    }
    return (0);
}
