/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for timesort.c
*/

#include <sys/types.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(timesort, normal)
{
    struct stat stat1;
    file_t file1 = {"test", &stat1};
    struct stat stat2;
    file_t file2 = {"test", &stat2};

    stat1.st_mtime = 100;
    stat1.st_mtime = 200;
    cr_assert_eq(timesort(&file1, &file2), -1);
    cr_assert_eq(timesort(&file2, &file1), 1);
    cr_assert_eq(timesort(&file1, &file1), 0);
}
