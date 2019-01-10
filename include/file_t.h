/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** File element structure
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define INFO_SIZE 7

enum field {F_MODE, F_LINK, F_OWNER, F_GROUP, F_MAJ, F_SIZE_MIN, F_TIME};

typedef struct file {
    char *name;
    struct stat *stat;
    char *link;
} file_t;
