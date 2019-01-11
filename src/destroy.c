/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Destroy data structures
*/

#include <stdlib.h>
#include "prototypes.h"

void destroy_file_list(file_t *files)
{
    for (int i = 0; files[i].name != NULL; i++) {
        free(files[i].name);
        free(files[i].stat);
        if (files[i].link[0] != '\0')
            free(files[i].link);
    }
    free(files);
}

void destroy_file_infos(char ***infos)
{
    for (int i = 0; infos[i] != NULL; i++) {
        for (int j = 0; j < INFO_SIZE; j++) {
            if (infos[i][j][0] != '\0')
                free(infos[i][j]);
        }
        free(infos[i]);
    }
    free(infos);
}
