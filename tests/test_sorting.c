/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** unit tests for sorting.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(is_sorted, normal)
{
    file_t sorted[4] = {{"a", NULL}, {"b", NULL}, {"c", NULL}, {NULL, NULL}};
    file_t unsorted[4] = {{"a", NULL}, {"c", NULL}, {"b", NULL}, {NULL, NULL}};
    file_t one[2] = {{"one", NULL}, {NULL, NULL}};
    file_t null[1] = {{NULL, NULL}};

    cr_assert(is_sorted(sorted, &my_alphasort));
    cr_assert_not(is_sorted(unsorted, &my_alphasort));
    cr_assert(is_sorted(one, &my_alphasort));
    cr_assert(is_sorted(null, &my_alphasort));
}

Test(bubble_sort, normal)
{
    file_t unsorted[5] = {{"lal", NULL}, {"+lol", NULL}, {"lul", NULL},
    {"bonjour", NULL}, {NULL, NULL}};
    file_t sorted[5] = {{"bonjour", NULL}, {"lal", NULL}, {"+lol", NULL},
    {"lul", NULL}, {NULL, NULL}};

    bubble_sort(unsorted, &my_alphasort);
    for (int i = 0; unsorted[i].name != NULL; i++)
        cr_assert_str_eq(unsorted[i].name, sorted[i].name);
}

Test(bubble_sort, empty_or_one)
{
    file_t one[2] = {{"one", NULL}, {NULL, NULL}};
    file_t null[1] = {{NULL, NULL}};

    bubble_sort(one, &my_alphasort);
    bubble_sort(null, &my_alphasort);
    cr_assert_str_eq(one[0].name, "one");
    cr_assert_eq(null[0].name, NULL);
}

Test(sort_files, reverse)
{
    file_t files[3] = {{"a", NULL}, {"b", NULL}, {NULL, NULL}};
    file_t files2[4] = {{"a", NULL}, {"b", NULL}, {"c", NULL}, {NULL, NULL}};
    char options[127] = {0};

    options['r'] = 1;
    sort_files(files, options);
    cr_assert_str_eq(files[0].name, "b");
    cr_assert_str_eq(files[1].name, "a");
    sort_files(files2, options);
    cr_assert_str_eq(files2[0].name, "c");
    cr_assert_str_eq(files2[1].name, "b");
    cr_assert_str_eq(files2[2].name, "a");
}
