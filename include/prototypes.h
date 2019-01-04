/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Prototypes
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "file_t.h"

// options.c
char *get_options(int ac, char **av);
char *create_charmap(void);
int parse_arg(char *arg, char *options);

// Utility functions
char *my_strdup(char const *str);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
void my_putstr(char *str);
int my_put_error(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

// read_dir.c
char **read_file_names(char *dirpath);
void extract_file_names(char *dirpath, char **list);

// sorting.c
int is_alpha(char c);
int is_sorted(char **list, int (*sorter)(char *, char *));
void bubble_sort(char **list, int (*sorter)(char *, char*));

// display.c
void display_directory(char *dir_path, int header);
void display_list(char **list);

// filepath.c
char *get_filepath(char *directory, char *file);

#endif
