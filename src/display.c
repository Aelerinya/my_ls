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
    if (display_all_files(files, options, 0))
        return (1);
    if (options['R'])
        display_all_directories(dir_path, files, 2, options);
    return (0);
}

int display_all_files(file_t *files, char *options, int no_total)
{
    char ***infos = NULL;
    int max[6] = {0};

    if (!options['l']) {
        for (int i = 0; files[i].name != NULL; i++) {
            my_putstr(files[i].name);
            my_putstr("\n");
        }
        return (0);
    }
    if ((infos = get_all_file_infos(files, no_total)) == NULL)
        return (1);
    for (int i = 0; files[i].name != NULL; i++)
        for (int j = 0; j < 6; j++)
            if (my_strlen(infos[i][j]) > max[j])
                max[j] = my_strlen(infos[i][j]);
    for (int i = 0; files[i].name != NULL; i++)
        display_file_list(files + i, infos[i], max);
    return (0);
}

void display_file_list(file_t *file, char **info, int *max)
{
    int padding;

    for (int j = 0; j < 6; j++) {
        padding = max[j] - my_strlen(info[j]);
        for (int i = 0; i < padding && (j == F_LINK || j == F_SIZE); i++)
            my_putstr(" ");
        my_putstr(info[j]);
        for (int i = 0; i < padding && (j == F_OWNER || j == F_GROUP); i++)
            my_putstr(" ");
        my_putstr(" ");
    }
    my_putstr(file->name);
    my_putstr(file->link);
    my_putstr("\n");
}
