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

Test(display_all_files, normal, .init = redirect)
{
    char options[127] = {0};
    file_t file[2] = {{"abc", NULL, NULL}, {NULL, NULL, NULL}};

    display_all_files(file, options, 0);
    cr_assert_stdout_eq_str("abc\n");
}

Test(display_directory, no_header_list, .init = redirect)
{
    char options[127] = {0};

    options['l'] = 1;
    display_directory("tests/test_dir", 0, options);
    cr_assert_stdout_eq_str("total 4\n"
    "drwxr-xr-x 2 lucie lucie 4096 Jan  2 21:36 directory\n"
    "-rw-r--r-- 1 lucie lucie    0 Jan  2 21:35 file\n"
    "lrwxrwxrwx 1 lucie lucie    4 Jan  2 21:37 link -> file\n");
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

    options['l'] = 1;
    options['r'] = 1;
    options['R'] = 1;
    options['t'] = 1;
    display_all_directories("tests", files, 0, options);
    cr_assert_stdout_eq_str("total 0\n"
    "-rw-r--r-- 1 lucie lucie 0 Jan  5 18:56 one\n");
}
