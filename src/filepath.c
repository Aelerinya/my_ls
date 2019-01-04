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
    int slash;
    int len;
    char *filepath;

    if (directory == NULL)
        return file;
    slash = (directory[my_strlen(directory) - 1] != '/');
    len = my_strlen(directory) + slash + my_strlen(file);
    if ((filepath = malloc(sizeof(char) * (len + 1))) == NULL)
        return NULL;
    *filepath = '\0';
    my_strcat(filepath, directory);
    if (slash)
        my_strcat(filepath, "/");
    my_strcat(filepath, file);
    return filepath;
}
