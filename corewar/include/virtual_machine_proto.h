/*
** EPITECH PROJECT, 2020
** virtual_machine.h
** File description:
** prototype for the_virtual_machine
*/

#ifndef VIRTUAL_H
#define VIRTUAL_H

#define MAX_CHAMPS (4)


//read_cor.c
void reada_file(champ_t *champ);

//tools.c
int power(int nb, int pow);
int get_type(char const *param, char *name);
int get_binary_type(char const *param);
int is_typed(int code);

<<<<<<< HEAD
//vm
void run_vm(vm_t *vm, champ_t *champs);

//process
void add_process(champ_t **champ, vm_t *vm);
void create_champ_process(vm_t *vm, champ_t **champs);

//print
void print_cycle(vm_t *vm);

//error_handling
void exit_w_msg(char *msg, vm_t *vm);
=======
//init_empty_champ.c
void init_empty_champ(champ_t champ[][4]);
>>>>>>> 35fe619340fcecd6412e44f92da5f2d81e1f99d6

#endif /* !VIRTUAL_H */
