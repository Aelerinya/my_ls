/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Sort files alphabetically
*/

#include <stdlib.h>
#include "prototypes.h"

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int my_alphasort(file_t *f1, file_t *f2)
{
    return sort_like_ls(f1->name, f2->name);
}

int sort_like_ls(char *s1, char *s2)
{
    int pos = 0;
    char *off;
    char c1;
    char c2;

    for (off = s1; !is_alpha(*off) && *off != '\0'; off++);
    s1 = (*off != '\0') ? off : s1;
    for (off = s2; !is_alpha(*off) && *off != '\0'; off++);
    s2 = (*off != '\0') ? off : s2;
    for (pos = 0; s1[pos] != '\0' || s2[pos] != '\0'; pos++) {
        c1 = (s1[pos] >= 'A' && s1[pos] <= 'Z') ? s1[pos] + 32 : s1[pos];
        c2 = (s2[pos] >= 'A' && s2[pos] <= 'Z') ? s2[pos] + 32 : s2[pos];
        if (c1 != c2 && is_alpha(c1) != is_alpha(c2))
            return (is_alpha(c1)) ? 1 : -1;
        else if (c1 != c2)
            return c1 - c2;
    }
    return (0);
}
