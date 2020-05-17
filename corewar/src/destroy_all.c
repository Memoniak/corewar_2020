/*
** EPITECH PROJECT, 2020
** destroy_all
** File description:
** destroy_all
*/

#include "corewar.h"

void destroy_operation_t(operation_t *op)
{
    operation_t *current = op;
    operation_t *next;

    while (current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void destroy_all_vm(parser_t *parser, operation_t *op, vm_t *vm)
{
    destroy_operation_t(op);
    if (parser) {
        for (int i = 0; i < parser->nb_players; i++) {
            free(vm->champ->file_name);
            free(vm->champ->prog);
        }
    free(vm->last_name);
    remove_all_process(vm);
    }
    free(parser);
}