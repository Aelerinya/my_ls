/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** options parser
*/

#include <unistd.h>
#include <stdlib.h>
#include "prototypes.h"
#include "options.h"

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

int is_valid(char option)
{
    for (int i = 0; valid_options[i] != '\0'; i++)
        if (valid_options[i] == option)
            return 1;
    return 0;
}

char *get_options(int ac, char **av)
{
    char *options = create_charmap();

    if (options == NULL)
        return NULL;
    for (int i = 1; i < ac; i++)
        parse_arg(av[i], options);
    for (int i = 0; i < 127; i++) {
        if (options[i] && !is_valid(i)) {
            my_put_error("Invalid option : ");
            write(2, &i, 1);
            my_put_error("\nTry -h for help.\n");
            return NULL;
        }
    }
    return options;
}
