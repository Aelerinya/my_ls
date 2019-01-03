/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Read a directory content and stores all file names
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "prototypes.h"

void extract_file_names(char *dirpath, char **list)
{
    DIR *dir = opendir(dirpath);
    struct dirent *file;
    int count = 0;

    while ((file = readdir(dir)) != NULL)
        if (file->d_name[0] != '.')
            list[count++] = my_strdup(file->d_name);
    closedir(dir);
}

char **read_file_names(char *dirpath)
{
    DIR *dir = opendir(dirpath);
    int count = 0;
    char **list;
    struct dirent *file;

    if (dir == NULL)
        return NULL;
    while ((file = readdir(dir)) != NULL)
        if (file->d_name[0] != '.')
            count++;
    closedir(dir);
    list = malloc(sizeof(char *) * (count + 1));
    if (list == NULL)
        return NULL;
    extract_file_names(dirpath, list);
    list[count] = NULL;
    return list;
}
