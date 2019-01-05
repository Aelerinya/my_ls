/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for error.c
*/

#include <errno.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

void redirect(void);

Test(my_raise, no_file, .init = redirect)
{
    errno = 1;
    cr_assert_eq(my_raise("test", NULL), NULL);
    cr_assert_stderr_eq_str("test: Operation not permitted\n");
}

Test(my_raise, with_file, .init = redirect)
{
    errno = 1;
    cr_assert_eq(my_raise("test ", "somedir/somefile"), NULL);
    cr_assert_stderr_eq_str("test somedir/somefile: Operation not permitted\n");
}

Test(memory_error, normal, .init = redirect)
{
    cr_assert_eq(memory_error(), NULL);
    cr_assert_stderr_eq_str("Could not allocate more memory.\n");
}
