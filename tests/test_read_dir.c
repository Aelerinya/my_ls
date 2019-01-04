/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for read_dir.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <criterion/criterion.h>
#include "prototypes.h"

Test(read_file_names, normal)
{
    char **list = read_file_names("tests/test_dir");
    char *theory[4] = {"file", "link", "directory", NULL};

    for (int i = 0; list[i] != NULL; i++)
        cr_assert_str_eq(list[i], theory[i]);
}

Test(read_file_names, invalid)
{
    cr_assert_eq(read_file_names("tests/no_dir"), NULL);
}

Test(convert_file_list, normal)
{
    char **list = read_file_names("tests/test_dir");
    file_t *files = convert_file_list("tests/test_dir", list);

    cr_assert_str_eq(files[0].name, "file");
    cr_assert(S_ISREG(files[0].stat->st_mode), "mode : %#o", files[0].stat->st_mode & S_IFMT);
    cr_assert_str_eq(files[1].name, "link");
    cr_assert(S_ISLNK(files[1].stat->st_mode), "mode : %#o", files[1].stat->st_mode & S_IFMT);
    cr_assert_str_eq(files[2].name, "directory");
    cr_assert(S_ISDIR(files[2].stat->st_mode), "mode : %#o", files[2].stat->st_mode & S_IFMT);
}

Test(convert_file_list, invalid)
{
    char *list[2] = {"not_a_file", NULL};
    file_t *files = convert_file_list("tests/test_dir", list);

    cr_assert_eq(files, NULL);
}
