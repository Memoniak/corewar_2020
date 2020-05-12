/*
** EPITECH PROJECT, 2020
** virtual_machine.h
** File description:
** prototype for the_virtual_machine
*/

#ifndef VIRTUAL_H
#define VIRTUAL_H

//read_cor.c
void reada_file(champ_t *champ);

//tools.c
int power(int nb, int pow);
int get_type(char const *param, char *name);
int get_binary_type(char const *param);
int is_typed(int code);

//init_empty_champ.c
void init_empty_champ(champ_t champ[][4]);

#endif /* !VIRTUAL_H */
