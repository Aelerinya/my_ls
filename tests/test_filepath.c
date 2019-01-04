/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for filepath.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(get_filepath, normal)
{
    cr_assert_str_eq(get_filepath("dir", "file"), "dir/file");
    cr_assert_str_eq(get_filepath("dir/", "file"), "dir/file");
}
