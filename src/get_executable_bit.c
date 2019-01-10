/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get executable bit characater of a file
*/

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
