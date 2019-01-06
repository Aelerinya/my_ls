/*
** EPITECH PROJECT, 2019
** my_nbr_to_str
** File description:
** Unit tests for my_nbr_to_str.c
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(my_nbr_to_str, normal)
{
    cr_assert_str_eq(my_nbr_to_str(-42), "-42");
    cr_assert_str_eq(my_nbr_to_str(84), "84");
    cr_assert_str_eq(my_nbr_to_str(0), "0");
    cr_assert_str_eq(my_nbr_to_str(1000000000), "1000000000");
}
