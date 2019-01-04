/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for parse_arguments.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(parse_arguments, normal)
{
    char *av[5] = {"./my_ls", "-flei", "dir", "--reverse", "#file"};
    int ac = 5;
    char **list = parse_arguments(ac, av);

    cr_assert_str_eq(list[0], "dir");
    cr_assert_str_eq(list[1], "#file");
    cr_assert_eq(list[2], NULL);
}

Test(parse_arguments, empty)
{
    char *av[2] = {"./my_ls", "-flei"};
    int ac = 2;
    char **list = parse_arguments(ac, av);

    cr_assert_eq(list[0], NULL);
}
