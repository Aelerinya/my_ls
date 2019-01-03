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
        files = read_file_names(".");
        bubble_sort(files, &my_strcmp);
        display_list(files);
    }
    return (0);
}
