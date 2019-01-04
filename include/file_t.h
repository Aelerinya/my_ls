/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** File element structure
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct file {
    char *name;
    struct stat *stat;
} file_t;
