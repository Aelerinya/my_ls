/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Prototypes
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

char *get_options(int ac, char **av);
char *create_charmap(void);
int parse_arg(char *arg, char *options);

char *my_strdup(char const *str);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
void my_putstr(char *str);
int my_put_error(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

char **read_file_names(char *dirpath);
void extract_file_names(char *dirpath, char **list);

int is_alpha(char c);
int is_sorted(char **list, int (*sorter)(char *, char *));
void bubble_sort(char **list, int (*sorter)(char *, char*));

void display_directory(char *dir_path, int header);
void display_list(char **list);

#endif
