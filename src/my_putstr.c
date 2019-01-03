/*
** EPITECH PROJECT, 2018
** push_swap
** File description:
** my_putstr, my_put_error and my_strlen
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int length;

    for (length = 0; str[length] != '\0'; length++);
    return length;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_put_error(char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}
