/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get other file infos
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "prototypes.h"

char get_executable_bit(file_t *file, int mask)
{
    int mode = file->stat->st_mode;
    int executable = mode & mask;
    int set_user_id = mode & S_ISUID;
    int set_group_id = mode & S_ISGID;
    int sticky = mode & S_ISVTX;

    if (mask == S_IXUSR && set_user_id)
        return (executable) ? 's' : 'S';
    if (mask == S_IXGRP && set_group_id)
        return (executable) ? 's' : 'S';
    if (mask == S_IXOTH && sticky)
        return (executable) ? 't' : 'T';
    return (executable) ? 'x' : '-';
}

void get_major_minor_size(file_t *file, char **info)
{
    char *major;
    int length;

    if (S_ISCHR(file->stat->st_mode) || S_ISBLK(file->stat->st_mode)) {
        major = my_nbr_to_str(major(file->stat->st_rdev));
        length = my_strlen(major);
        if ((info[F_MAJ] = malloc(sizeof(char) * (length + 2))) != NULL) {
            my_strncpy(info[F_MAJ], major, length);
            info[F_MAJ][length] = ',';
            info[F_MAJ][length + 1] = '\0';
        }
        info[F_SIZE_MIN] = my_nbr_to_str(minor(file->stat->st_rdev));
    } else {
        info[F_MAJ] = "";
        info[F_SIZE_MIN] = my_nbr_to_str(file->stat->st_size);
    }
}
