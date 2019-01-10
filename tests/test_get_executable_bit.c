/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for get_executable_bit.c
*/

#include <sys/stat.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(get_executable_bit, normal)
{
    struct stat stats;
    file_t file = {NULL, &stats, NULL};

    stats.st_mode = 0;
    cr_assert_eq(get_executable_bit(&file, S_IXUSR), '-');
    stats.st_mode = S_IXUSR;
    cr_assert_eq(get_executable_bit(&file, S_IXUSR), 'x');
    stats.st_mode = S_IXUSR | S_ISUID;
    cr_assert_eq(get_executable_bit(&file, S_IXUSR), 's');
    stats.st_mode = S_ISUID;
    cr_assert_eq(get_executable_bit(&file, S_IXUSR), 'S');
    stats.st_mode = S_IXGRP | S_ISGID;
    cr_assert_eq(get_executable_bit(&file, S_IXGRP), 's');
    stats.st_mode = S_ISGID;
    cr_assert_eq(get_executable_bit(&file, S_IXGRP), 'S');
    stats.st_mode = S_IXOTH | S_ISVTX;
    cr_assert_eq(get_executable_bit(&file, S_IXOTH), 't');
    stats.st_mode = S_ISVTX;
    cr_assert_eq(get_executable_bit(&file, S_IXOTH), 'T');
}
