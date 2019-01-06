/*
** EPITECH PROJECT, 2018
** my_nbr_to_str
** File description:
** Convert an int into a string
*/

#include <stdlib.h>
#include "prototypes.h"

char *my_nbr_to_str(long long int nb)
{
    char *str;
    int negative = nb < 0;
    int size = 2 + negative;

    nb = (nb < 0) ? -nb : nb;
    for (long long int power = 10; power <= nb; power *= 10, size++);
    if ((str = malloc(sizeof(char) * size)) == NULL)
        return memory_error();
    str[0] = '-';
    str[size - 1] = '\0';
    for (int i = size - 2; i >= negative; i--) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}
