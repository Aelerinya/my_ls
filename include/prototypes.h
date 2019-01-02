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

char **read_file_names(char *dirpath);
void extract_file_names(char *dirpath, char **list);

#endif
