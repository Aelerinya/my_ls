/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** tests for my_strcat()
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(my_strcat, normal)
{
    char *s1 = "lol";
    char *ss1 = malloc(sizeof(char) * 4);
    char *s2 = "haha";
    char *ss2 = malloc(sizeof(char) * 5);
    char *theory = "lolhaha";
    char *dest;

    my_strncpy(ss1, s1, 4);
    my_strncpy(ss2, s2, 5);
    dest = my_strcat(ss1, ss2);
    cr_assert_str_eq(dest, theory);
}

Test(my_strcat, empty)
{
    char *s1 = "";
    char *ss1 = malloc(sizeof(char) * 1);
    char *s2 = "haha";
    char *ss2 = malloc(sizeof(char) * 5);
    char *theory = "haha";
    char *dest;

    my_strncpy(ss1, s1, 1);
    my_strncpy(ss2, s2, 5);
    dest = my_strcat(ss1, ss2);
    cr_assert_str_eq(dest, theory);
}
