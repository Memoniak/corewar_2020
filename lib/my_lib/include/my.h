/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header of libmy
*/

#ifndef MY_H
#define MY_H

/* INCLUDES ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
/* !INCLUDES -----------------------------------------------------------------*/

/* PROTO ---------------------------------------------------------------------*/
//my_getlen.c
int my_strlen(char const *str);
int my_arrlen(char *array[]);

//my_getnbr.c
int my_getnbr(char const *str);
float my_getflt(char *str);

//my_getword.c
int next_word(char const *str);
char *my_getword(char const *str);

//my_remalloc.c
bool my_remalloc(char **str, size_t size);

//my_revstr.c
char *my_revstr(char *str);

//my_strcat.c
char *my_strcat(char *dest, char const *str);

//my_strcmp.c
bool my_strcmp(char const *first, char const *second);

//my_strncmp.c
int my_strncmp(char const *s1, char const *s2, int n);

//my_strdup.c
char *my_strndup(char *dest, char *src, int n);
char *my_strdup(char const *src);
char *my_strdup_start(char const *src, int pos);
char *my_strdup_w_no_spaces(char const *src);
char *my_strdup_start_no_sp(char const *src, int pos);
char *my_strndup(char *dest, char *src, int n);

//my_strcpy.c
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char *str);
char **my_arrcpy(char **dest, char **arr);

//my_int_to_str.c
int count_num(int nb);
char *intchar(int nb);

//is_num.c
int is_num(char str);

//custom_strlen.c
int custom_strlen(char *str, char limit);

//get_file_content.c
bool get_file(char **str, char const *filepath);

//str_to_word_array.c
char **word_array(char const *str, char c);
void free_array(char **array);
/* !PROTO --------------------------------------------------------------------*/

#endif /*MY_H*/
