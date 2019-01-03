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

char **read_file_names(char *dirpath);
void extract_file_names(char *dirpath, char **list);

int is_sorted(char **list, int (*sorter)(char *, char *));
void bubble_sort(char **list, int (*sorter)(char *, char*));

#endif
