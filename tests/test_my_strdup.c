/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Unit tests for my_strdup
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(my_strdup, normal)
{
    char *src = "abc";
    char *dest = my_strdup(src);

    cr_assert_str_eq(dest, src);
}

Test(my_strdup, empty)
{
    char *src = "";
    char *dest = my_strdup(src);

    cr_assert_str_eq(dest, src);
}

Test(my_strdup, null)
{
    char *dest = my_strdup(NULL);

    cr_assert_eq(dest, NULL);
}
