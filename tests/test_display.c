/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for display.c
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

void redirect(void);

Test(display_list, normal, .init = redirect)
{
    file_t file = {"abc", NULL};

    display_file(&file);
    cr_assert_stdout_eq_str("abc\n");
}

Test(display_directory, no_header, .init = redirect)
{
    char options[127] = {0};

    display_directory("tests/test_dir", 0, options);
    cr_assert_stdout_eq_str("directory\nfile\nlink\n");
}

Test(display_directory, header, .init = redirect)
{
    char options[127] = {0};

    display_directory("tests/test_dir", 1, options);
    cr_assert_stdout_eq_str("tests/test_dir:\ndirectory\nfile\nlink\n");
}
