/*
** EPITECH PROJECT, 2019
** my.h printf
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct args {
    char *arg;
    char * (*ptr)();
} args_t;

typedef struct padding {
    int *padding;
    char checker;
    int old_len;
} pad_t;

typedef struct string_s {
    char *buff;
    char s;
} string_t;

typedef struct flag_s {
    int tmp;
    int c_0;
    int flag;
    pad_t pad_s;
} flag_t;

char *my_realloc(char *str, int size);
int my_printf(char *s, ...);
char *my_put_nbr(int nb);
char *my_putchar_b(char c);
int my_putstr(char const *str);
char *non_p_s(char const *str);
char *to_binary(int nb);
int my_strlen(char const *str);
char *my_revstr(char const *str);
char *to_octal(int x);
char *conv_hexa(int nb);
char *conv_octal(unsigned int x);
int padded(int len);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_putnbr_buff(int nb);
char *my_strdup(char const *src);
char *conv_hexa_c(int nb);
char *my_putstr_b(char const *str);
void my_putchar(char c);
char *padding();
int get_nbr_len(long nb);
char *my_strcpy(char *dest, char const *src);
int *get_padded_nb(char *str, int pos, args_t const *fct);
char *add_padding(char *buffer, char *cpy, int padding, int old_len);
char *init_buffer(void);
int *init_padded_num(void);
char *flag_true(char *buffer, int flag, char *s, int i);
int check_flags(char s, int pos, char *str, char *buffer);
char *init_cpy(char *buffer);
char *check_buffer(char *buffer);
int my_strcmp(char const *s1, char const *s2);
