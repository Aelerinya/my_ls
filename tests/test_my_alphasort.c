/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for my_alphasort.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(sort_like_ls, normal)
{
    cr_assert_eq(sort_like_ls("aa", "a"), 1);
    cr_assert_eq(sort_like_ls("a", "a "), -32);
    cr_assert_eq(sort_like_ls("abC", "abD"), -1);
    cr_assert_eq(sort_like_ls("", ""), 0);
    cr_assert_eq(sort_like_ls("lo.", "lol"), -1);
    cr_assert_eq(sort_like_ls("lol", "lo~"), 1);
}

Test(is_alpha, normal)
{
    cr_assert_eq(is_alpha('\0'), 0);
    cr_assert_eq(is_alpha('3'), 1);
    cr_assert_eq(is_alpha('Z'), 1);
    cr_assert_eq(is_alpha('e'), 1);
    cr_assert_eq(is_alpha('~'), 0);
}
