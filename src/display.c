/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Display the file name lists
*/

#include <stdlib.h>
#include "prototypes.h"

int display_all_directories(char *parent_path,
file_t *files, int header, char *options)
{
    char *path;
    int first = 1;

    for(int i = 0; files[i].name != NULL; i++) {
        if (S_ISDIR(files[i].stat->st_mode)) {
            my_putstr((!first || header == 2) ? "\n" : "");
            first = 0;
            path = get_filepath(parent_path, files[i].name);
            if (display_directory(path, header, options))
                return (1);
        }
    }
    return (0);
}

int display_directory(char *dir_path, int header, char *options)
{
    char **list;
    file_t *files;

    if ((list = read_file_names(dir_path)) == NULL)
        return (1);
    if ((files = convert_file_list(dir_path, list)) == NULL)
        return (1);
    sort_files(files, options);
    if (header) {
        my_putstr(dir_path);
        my_putstr(":\n");
    }
    for (int i = 0; files[i].name != NULL; i++)
        display_file(files + i, options);
    if (options['R'])
        display_all_directories(dir_path, files, 2, options);
    return (0);
}
