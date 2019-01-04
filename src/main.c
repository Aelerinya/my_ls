/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** main function
*/

#include <stdio.h>
#include "prototypes.h"

int main(int ac, char **av)
{
    char *options = get_options(ac, av);
    char **files;

    if (ac == 1) {
        display_directory(".");
        return 0;
    }
    return (0);
}
