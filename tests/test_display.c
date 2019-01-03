/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for display.c
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

void redirect(void);

Test(display_list, normal, .init = redirect)
{
    char *list[5] = {"abc", "lol", "x", "", NULL};

    display_list(list);
    cr_assert_stdout_eq_str("abc\nlol\nx\n\n");
}
