/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** unit tests for sorting.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "prototypes.h"

file_t *create_test_list(char **list)
{
    int len;
    file_t *files;

    for (len = 0; list[len] != NULL; len++);
    files = malloc(sizeof(file_t) * (len + 1));
    for (int i = 0; list[i] != NULL; i++) {
        files[i].name = list[i];
        files[i].stat = NULL;
        files[i].link = NULL;
    }
    return files;
}

Test(is_sorted, normal)
{
    char *list[5] = {"a", "b", "c", "d", NULL};
    file_t *sorted = create_test_list(list);
    char *list2[4] = {"a", "c", "b", NULL};
    file_t *unsorted = create_test_list(list2);
    file_t one[2] = {{"one", NULL, NULL}, {NULL, NULL, NULL}};
    file_t null[1] = {{NULL, NULL, NULL}};

    cr_assert(is_sorted(sorted, &my_alphasort));
    cr_assert_not(is_sorted(unsorted, &my_alphasort));
    cr_assert(is_sorted(one, &my_alphasort));
    cr_assert(is_sorted(null, &my_alphasort));
}

Test(bubble_sort, normal)
{
    char *list[5] = {"lal", "+lol", "lul", "bonjour", NULL};
    file_t *unsorted = create_test_list(list);
    char *list2[5] = {"bonjour", "lal", "+lol", "lul", NULL};
    file_t *sorted = create_test_list(list2);

    bubble_sort(unsorted, &my_alphasort);
    for (int i = 0; unsorted[i].name != NULL; i++)
        cr_assert_str_eq(unsorted[i].name, sorted[i].name);
}

Test(bubble_sort, empty_or_one)
{
    file_t one[2] = {{"one", NULL, NULL}, {NULL, NULL, NULL}};
    file_t null[1] = {{NULL, NULL, NULL}};

    bubble_sort(one, &my_alphasort);
    bubble_sort(null, &my_alphasort);
    cr_assert_str_eq(one[0].name, "one");
    cr_assert_eq(null[0].name, NULL);
}

Test(sort_files, reverse)
{
    char *list[3] = {"a", "b", NULL};
    file_t *files = create_test_list(list);
    char *list2[4] = {"a", "b", "c", NULL};
    file_t *files2 = create_test_list(list2);
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
