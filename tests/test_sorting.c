/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** unit tests for sorting.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(my_strcmp, normal)
{
    cr_assert_eq(my_strcmp("aa", "a"), 1);
    cr_assert_eq(my_strcmp("a", "a "), -32);
    cr_assert_eq(my_strcmp("abC", "abD"), -1);
    cr_assert_eq(my_strcmp("", ""), 0);
    cr_assert_eq(my_strcmp("lo.", "lol"), -1);
    cr_assert_eq(my_strcmp("lol", "lo~"), 1);
}

Test(is_sorted, normal)
{
    char *sorted[4] = {"a", "b", "c", NULL};
    char *unsorted[4] = {"a", "c", "b", NULL};
    char *one[2] = {"one", NULL};
    char *null[1] = {NULL};

    cr_assert(is_sorted(sorted, &my_strcmp));
    cr_assert_not(is_sorted(unsorted, &my_strcmp));
    cr_assert(is_sorted(one, &my_strcmp));
    cr_assert(is_sorted(null, &my_strcmp));
}

Test(is_alpha, normal)
{
    cr_assert_eq(is_alpha('\0'), 0);
    cr_assert_eq(is_alpha('3'), 0);
    cr_assert_eq(is_alpha('Z'), 1);
    cr_assert_eq(is_alpha('e'), 1);
}

Test(bubble_sort, normal)
{
    char *unsorted[5] = {"lal", "+lol", "lul", "bonjour", NULL};
    char *sorted[5] = {"bonjour", "lal", "+lol", "lul", NULL};

    bubble_sort(unsorted, &my_strcmp);
    for (int i = 0; unsorted[i] != NULL; i++)
        cr_assert_str_eq(unsorted[i], sorted[i]);
}

Test(bubble_sort, empty_or_one)
{
    char *one[2] = {"one", NULL};
    char *null[1] = {NULL};

    bubble_sort(one, &my_strcmp);
    bubble_sort(null, &my_strcmp);
    cr_assert_str_eq(*one, "one");
    cr_assert_eq(*null, NULL);
}
