/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Functions to display a file's informations
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "prototypes.h"

static char get_file_type(file_t *file)
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

static void display_mode(file_t *file)
{
    char mode[12];

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
    mode[10] = ' ';
    mode[11] = '\0';
    my_putstr(mode);
}

static void display_owner_group(file_t *file)
{
    struct passwd *pass = getpwuid(file->stat->st_uid);
    struct group *grp = getgrgid(file->stat->st_gid);

    my_putstr(" ");
    my_putstr((pass) ? pass->pw_name : "?");
    my_putstr(" ");
    my_putstr((grp) ? grp->gr_name : "?");
    my_putstr(" ");
}

static void display_time(file_t *file)
{
    time_t timestamp = file->stat->st_mtime;
    char *time;

    my_putstr(" ");
    time = ctime(&timestamp);
    if (time)
        time[my_strlen(time) - 1] = '\0';
    my_putstr((time) ? time : "?");
    my_putstr(" ");
}

void display_file(file_t *file, char *options)
{
    if (options['l']) {
        display_mode(file);
        my_putstr(my_nbr_to_str(file->stat->st_nlink));
        display_owner_group(file);
        my_putstr(my_nbr_to_str(file->stat->st_size));
        display_time(file);
    }
    my_putstr(file->name);
    my_putstr("\n");
}
