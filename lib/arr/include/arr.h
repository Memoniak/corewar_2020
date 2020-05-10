/*
** EPITECH PROJECT, 2020
** arr.h
** File description:
** lib include file
*/

#ifndef ARR_H_
#define ARR_H_

#include <stdio.h>
#include <stdlib.h>

size_t get_dbl_arr_len(char const **arr);
char *get_string_inbetween(char *str, char op);
char **my_parser(char *str, char seperator);
char *my_memset(int len, char *str);
char *remove_tabs(char *str);
char *remove_spaces(char *str);
char *remove_first_spaces(char *str);
char *copy_from_start(char *str, char *dest, int pos);

#endif /* !ARR_H_ */
