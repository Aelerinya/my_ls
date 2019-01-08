/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** main function
*/

#include <stdlib.h>
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
        display_directory(".", options['R'], options);
        return 0;
    }
    if ((files = convert_file_list(NULL, list)) == NULL)
        return (84);
    sort_files(files, options);
    if (separate_files_and_directory(files, options))
        return (84);
    return (0);
}

file_t *remove_directories(file_t *files)
{
    int file_count = 0;
    file_t *only_files;

    for (int i = 0; files[i].name != NULL; i++)
        if (!S_ISDIR(files[i].stat->st_mode))
            file_count++;
    if ((only_files = malloc(sizeof(file_t) * (file_count + 1))) == NULL)
        return memory_error();
    only_files[file_count].name = NULL;
    file_count = 0;
    for (int i = 0; files[i].name != NULL; i++)
        if (!S_ISDIR(files[i].stat->st_mode))
            only_files[file_count++] = files[i];
    return only_files;
}

int separate_files_and_directory(file_t *files, char *options)
{
    int header = (files[1].name != NULL) || options['R'];
    int is_there_regular_files = 0;
    int is_there_directories = 0;
    file_t *no_dir = remove_directories(files);

    for (int i = 0; files[i].name != NULL; i++) {
        if (options['d'] || S_ISREG(files[i].stat->st_mode))
            is_there_regular_files = 1;
        else if (S_ISDIR(files[i].stat->st_mode))
            is_there_directories = 1;
    }
    if (display_all_files((options['d'] ? files : no_dir), options, 1))
        return (1);
    my_putstr(is_there_regular_files && is_there_directories ? "\n" : "");
    if (display_all_directories(NULL, files, header, options))
        return (1);
    return (0);
}
