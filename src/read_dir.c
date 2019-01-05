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

file_t *convert_file_list(char *directory, char **file_names)
{
    int len;
    file_t *files;
    char *filepath;

    for (len = 0; file_names[len] != NULL; len++);
    if ((files = malloc(sizeof(file_t) * (len + 1))) == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        files[i].name = file_names[i];
        filepath = get_filepath(directory, file_names[i]);
        files[i].stat = malloc(sizeof(struct stat));
        if (filepath == NULL || files[i].stat == NULL)
            return NULL;
        if (lstat(filepath, files[i].stat) == -1)
            return NULL;
        if (directory != NULL)
            free(filepath);
    }
    files[len].name = NULL;
    return files;
}
