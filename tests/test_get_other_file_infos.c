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

Test(get_major_minor_size, all)
{
    char *list[3] = {"/dev/urandom", "./tests/test_dir2/one", NULL};
    file_t *files = convert_file_list(NULL, list);
    char *info[7];

    get_major_minor_size(files + 0, info);
    cr_assert_str_eq(info[F_MAJ], "1,");
    cr_assert_str_eq(info[F_SIZE_MIN], "9");
    get_major_minor_size(files + 1, info);
    cr_assert_str_eq(info[F_MAJ], "");
    cr_assert_str_eq(info[F_SIZE_MIN], "0");
}
