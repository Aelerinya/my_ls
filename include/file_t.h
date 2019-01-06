/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** File element structure
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

enum field {F_MODE, F_LINK, F_OWNER, F_GROUP, F_SIZE, F_TIME};

typedef struct file {
    char *name;
    struct stat *stat;
} file_t;
