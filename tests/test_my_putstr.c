/*
** EPITECH PROJECT, 2018
** push_swap
** File description:
** Criterion unit tests for my_putstr and similar funcitons
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strlen, all)
{
    cr_assert_eq(my_strlen("123"), 3);
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_putstr, all, .init = redirect)
{
    my_putstr("abc");
    cr_assert_stdout_eq_str("abc");
}

Test(my_put_error, all, .init = redirect)
{
    cr_assert_eq(my_put_error("abc"), 84);
    cr_assert_stderr_eq_str("abc");
}
