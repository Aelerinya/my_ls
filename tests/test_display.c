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
    char options[127] = {0};
    file_t file = {"abc", NULL};

    display_file(&file, options);
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

Test(display_all_directories, normal, .init = redirect)
{
    char options[127] = {0};
    char **list = read_file_names("tests");
    file_t *files = convert_file_list("tests", list);

    options['R'] = 1;
    sort_files(files, options);
    display_all_directories("tests", files, 1, options);
    cr_assert_stdout_eq_str("tests/test_dir:\ndirectory\nfile\nlink\n\n"
    "tests/test_dir/directory:\n\ntests/test_dir2:\none\n");
}

Test(display_all_directories, one, .init = redirect)
{
    char options[127] = {0};
    char *list[2] = {"test_dir2", NULL};
    file_t *files = convert_file_list("tests", list);

    display_all_directories("tests", files, 0, options);
    cr_assert_stdout_eq_str("one\n");
}
