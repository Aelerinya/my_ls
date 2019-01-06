/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Functions to retrive a file's informations as strings
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "prototypes.h"

char get_file_type(file_t *file)
{
    if (S_ISREG(file->stat->st_mode))
        return '-';
    if (S_ISDIR(file->stat->st_mode))
        return 'd';
    if (S_ISCHR(file->stat->st_mode))
        return 'c';
    if (S_ISBLK(file->stat->st_mode))
        return 'b';
    if (S_ISFIFO(file->stat->st_mode))
        return 'p';
    if ((file->stat->st_mode & S_IFMT) == S_IFLNK)
        return 'l';
    if ((file->stat->st_mode & S_IFMT) == S_IFSOCK)
        return 's';
    return '?';
}

char *get_mode(file_t *file)
{
    char *mode = malloc(sizeof(char) * 11);

    if (mode == NULL)
        return memory_error();
    mode[0] = get_file_type(file);
    mode[1] = (file->stat->st_mode & S_IRUSR) ? 'r' : '-';
    mode[2] = (file->stat->st_mode & S_IWUSR) ? 'w' : '-';
    mode[3] = (file->stat->st_mode & S_IXUSR) ? 'x' : '-';
    mode[4] = (file->stat->st_mode & S_IRGRP) ? 'r' : '-';
    mode[5] = (file->stat->st_mode & S_IWGRP) ? 'w' : '-';
    mode[6] = (file->stat->st_mode & S_IXGRP) ? 'x' : '-';
    mode[7] = (file->stat->st_mode & S_IROTH) ? 'r' : '-';
    mode[8] = (file->stat->st_mode & S_IWOTH) ? 'w' : '-';
    mode[9] = (file->stat->st_mode & S_IXOTH) ? 'x' : '-';
    mode[10] = '\0';
    return mode;
}

char *get_time(file_t *file)
{
    time_t timestamp = file->stat->st_mtime;
    char *raw_time;
    char *time = malloc(sizeof(char) * 13);

    if (time == NULL)
        return memory_error();
    raw_time = ctime(&timestamp);
    if (raw_time)
        my_strncpy(time, raw_time + 4, 12);
    else
        my_strncpy(time, "?", 2);
    time[12] = '\0';
    return time;
}

char **get_file_info(file_t *file, long *total)
{
    struct passwd *pass = getpwuid(file->stat->st_uid);
    struct group *grp = getgrgid(file->stat->st_gid);
    char **info = malloc(sizeof(char *) * 6);

    if (info == NULL)
        return memory_error();
    info[F_MODE] = get_mode(file);
    info[F_LINK] = my_nbr_to_str(file->stat->st_nlink);
    info[F_OWNER] = my_strdup((pass) ? pass->pw_name : "?");
    info[F_GROUP] = my_strdup((grp) ? grp->gr_name : "?");
    info[F_SIZE] = my_nbr_to_str(file->stat->st_size);
    info[F_TIME] = get_time(file);
    *total += file->stat->st_blocks;
    return info;
}

char ***get_all_file_infos(file_t *files)
{
    char ***infos;
    int len;
    long total = 0;

    for (len = 0; files[len].name != NULL; len++);
    if ((infos = malloc(sizeof(char **) * (len + 1))) == NULL)
        return memory_error();
    infos[len] = NULL;
    for (int i = 0; i < len; i++) {
        if ((infos[i] = get_file_info(files + i, &total)) == NULL)
            return NULL;
    }
    my_putstr("total ");
    my_putstr(my_nbr_to_str(total / 2));
    my_putstr("\n");
    return infos;
}
