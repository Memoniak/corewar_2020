/*
** EPITECH PROJECT, 2019
** my_printf.h
** File description:
** header of my_printf
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

#define UNSD __attribute__((unused))
#define REALSIZE(value) (sizeof(value) / sizeof(value[0]))

typedef struct print_s {
    char car;
    void (*ptr)();
} print_t;

typedef struct flags_s{
    int quot;
    int rest;
    char c;
    int i;
    char *str;
} flags_t;

typedef struct unsflags_s{
    unsigned int quot;
    unsigned int rest;
    char c;
    int i;
    char *str;
} unsflags_t;

void my_printf(int output, char *str, ...);

int my_strlen(char const *str);
char *my_revstr(char *str);

void void_putchar(int output, int nb);
void void_putstr(int output, char const *str);
void void_put_nbr(int output, int nb);
void void_putfloat(int output, double nb);
void void_puthexa(int output, int nb);
void void_puthexa_c(int output, int nb);
void void_putbin(int output, unsigned int nb);
void void_putoctal(int output, unsigned int nb);
void void_putunsnbr(int output, unsigned int nb);
void void_putoct(int output, char *str);
void void_put_word_array(int output, char **array);
void void_putword_array(int output, char **array);

#endif /*MY_PRINTF_H*/
