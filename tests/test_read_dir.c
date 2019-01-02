/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for read_dir.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(read_file_names, normal)
{
    char **list = read_file_names("tests/test_dir");
    char *theory[7] = {".", "file", "link", "..", "directory", ".hidden", NULL};

    for (int i = 0; list[i] != NULL; i++)
        cr_assert_str_eq(list[i], theory[i]);
}

Test(read_file_names, invalid)
{
    cr_assert_eq(read_file_names("tests/no_dir"), NULL);
}
