/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** options parser
*/

#include <stdlib.h>
#include "prototypes.h"

char *create_charmap(void)
{
    char *map = malloc(sizeof(char) * 127);

    if (map == NULL)
        return memory_error();
    for (int i = 0; i < 127; i++)
        map[i] = 0;
    return map;
}

int parse_arg(char *arg, char *options)
{
    if (*arg != '-')
        return 1;
    for (int i = 1; arg[i] != '\0'; i++)
        options[(int)arg[i]] = 1;
    return 0;
}

char *get_options(int ac, char **av)
{
    char *options = create_charmap();

    if (options == NULL)
        return NULL;
    for (int i = 1; i < ac; i++)
        parse_arg(av[i], options);
    return options;
}
