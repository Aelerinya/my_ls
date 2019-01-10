/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Unit tests for get_file_infos.c
*/

#include <sys/stat.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

void redirect(void);

Test(get_file_type, all)
{
    struct stat stats;
    file_t file = {NULL, &stats, NULL};

    stats.st_mode = S_IFREG;
    cr_assert_eq(get_file_type(&file), '-');
    stats.st_mode = S_IFDIR;
    cr_assert_eq(get_file_type(&file), 'd');
    stats.st_mode = S_IFCHR;
    cr_assert_eq(get_file_type(&file), 'c');
    stats.st_mode = S_IFBLK;
    cr_assert_eq(get_file_type(&file), 'b');
    stats.st_mode = S_IFIFO;
    cr_assert_eq(get_file_type(&file), 'p');
    stats.st_mode = S_IFLNK;
    cr_assert_eq(get_file_type(&file), 'l');
    stats.st_mode = S_IFSOCK;
    cr_assert_eq(get_file_type(&file), 's');
    stats.st_mode = 0;
    cr_assert_eq(get_file_type(&file), '?');
}

Test(get_mode, all)
{
    struct stat stats;
    file_t file = {NULL, &stats, NULL};

    stats.st_mode = S_IFREG;
    cr_assert_str_eq(get_mode(&file), "----------");
    stats.st_mode |= S_IRWXU;
    stats.st_mode |= S_IRWXG;
    stats.st_mode |= S_IRWXO;
    cr_assert_str_eq(get_mode(&file), "-rwxrwxrwx");
}

Test(get_time, all)
{
    struct stat stats;
    file_t file = {NULL, &stats, NULL};

    stats.st_mtime = 1546820389;
    cr_assert_str_eq(get_time(&file), "Jan  7 01:19");
}

Test(get_all_file_infos, all, .init = redirect)
{
    char **list = read_file_names("tests/test_dir2");
    file_t *files = convert_file_list("tests/test_dir2", list);
    char ***infos = get_all_file_infos(files, 0);

    cr_assert_stdout_eq_str("total 0\n");
    cr_assert_str_eq(infos[0][F_MODE], "-rw-r--r--");
    cr_assert_str_eq(infos[0][F_LINK], "1");
    cr_assert_str_eq(infos[0][F_OWNER], "lucie");
    cr_assert_str_eq(infos[0][F_GROUP], "lucie");
    cr_assert_str_eq(infos[0][F_MAJ], "");
    cr_assert_str_eq(infos[0][F_SIZE_MIN], "0");
    cr_assert_str_eq(infos[0][F_TIME], "Jan  5 18:56");
    cr_assert_eq(infos[1], NULL);
}
