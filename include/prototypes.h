/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Prototypes
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "file_t.h"

int separate_files_and_directory(file_t *files, char *options);

// options.c
char *get_options(int ac, char **av);
char *create_charmap(void);
int parse_arg(char *arg, char *options);

// Utility functions
char *my_strdup(char const *str);
int my_strlen(char *str);
void my_putstr(char *str);
int my_put_error(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_nbr_to_str(long long int nb);

// read_dir.c
char **read_file_names(char *dirpath);
void extract_file_names(char *dirpath, char **list);
file_t *convert_file_list(char *directory, char **file_names);

// my_alphasort.c
int my_alphasort(file_t *f1, file_t *f2);
int sort_like_ls(char *s1, char *s2);
int is_alpha(char c);

// timesort.c
int timesort(file_t *f1, file_t *f2);

// sorting.c
void sort_files(file_t *files, char *options);
void reverse_list(file_t *files);
int is_sorted(file_t *files, int (*sorter)(file_t *, file_t *));
void bubble_sort(file_t *files, int (*sorter)(file_t *, file_t *));

// display.c
int display_all_directories(char *parent_path,
file_t *files, int header, char *options);
int display_directory(char *dir_path, int header, char *options);

// display_file.c
void display_file(file_t *file, char *options);

// filepath.c
char *get_filepath(char *directory, char *file);

// parse_arguments.c
char **parse_arguments(int ac, char **av);

// error.c
void *my_raise(char *error, char *file);
void *memory_error(void);

#endif
