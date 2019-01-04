/*
** EPITECH PROJECT, 2019
** my_ls.c
** File description:
** Create a filepath from a directory and a file name
*/

#include <stdlib.h>
#include "prototypes.h"

char *get_filepath(char *directory, char *file)
{
    int len_dir = my_strlen(directory);
    int len_file = my_strlen(file);
    int slash = (directory[len_dir - 1] != '/');
    int len = len_dir + slash + len_file;
    char *filepath = malloc(sizeof(char) * (len + 1));

    *filepath = '\0';
    my_strcat(filepath, directory);
    if (slash)
        my_strcat(filepath, "/");
    my_strcat(filepath, file);
    return filepath;
}
