/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** unit tests for options
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(create_charmap, normal)
{
    char *map = create_charmap();

    for (int i = 0; i < 127; i++)
        cr_assert_not(map[i]);
}

Test(parse_arg, normal)
{
    char *map = create_charmap();

    cr_assert_not(parse_arg("-lE.\n", map));
    cr_assert(map['l']);
    cr_assert(map['E']);
    cr_assert(map['.']);
    cr_assert(map['\n']);
    cr_assert(parse_arg("lol", map));
}

Test(get_options, normal)
{
    int ac = 4;
    char *av[4] = {"./my_ls", "-lAh", "test", "-li"};
    char *map = get_options(ac, av);

    cr_assert(map['l']);
    cr_assert(map['A']);
    cr_assert(map['h']);
    cr_assert(map['i']);
    cr_assert_not(map['z']);
    cr_assert_not(map['-']);
}
