/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup() function
*/

#include <stdlib.h>

char *my_strdup(char const *str)
{
    int length;
    char *dup;

    if (str == NULL)
        return NULL;
    for (length = 0; str[length] != '\0'; length++);
    dup = malloc(sizeof(char) * (length + 1));
    if (dup == NULL)
        return NULL;
    for (int i = 0; i < length; i++)
        dup[i] = str[i];
    dup[length] = '\0';
    return dup;
}
