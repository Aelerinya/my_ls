/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** tests for my_strncpy()
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(my_strncpy, normal)
{
    char *src = "lol";
    char dest[2];

    my_strncpy(dest, src, 2);
    cr_assert_eq(dest[0], 'l');
    cr_assert_eq(dest[1], 'o');
}

Test(my_strncpy, longer)
{
    char *src = "lol";
    char dest[5];

    my_strncpy(dest, src, 5);
    cr_assert_str_eq(dest, src);
}
