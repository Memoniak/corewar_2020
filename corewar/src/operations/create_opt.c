/*
** EPITECH PROJECT, 2020
** create_opt.c
** File description:
** init an otp chain list
*/

#include "corewar.h"

operation_t *opt_create(void)
{
    operation_t *opt = malloc(sizeof(operation_t));

    opt->index = 0;
    opt->code = 0;
    opt->nb_cycles = 0;
    opt->pcode = 0;
    opt->params = 0;
    opt->param_types = 0;
    opt->next = NULL;
    return opt;
}

int opt_length(operation_t *opt)
{
    int length = 0;

    while (opt)
    {
        ++length;
        opt = opt->next;
    }
    return length;
}

void opt_display(operation_t *opt)
{
    if (!opt)
    {
        my_printf(2, SREDN, "Error operation struct is Empty");
        return;
    }
    while (opt)
    {
        my_printf(2, SWHITEN, "━━━━━━━━━━━━━━━━━━━━━━");
        my_printf(2, SDLMAGENTAN, "index = ", opt->index);
        my_printf(2, SDTEALN, "code = ", opt->code);
        my_printf(2, SDGREENN, "nb_cycles = ", opt->nb_cycles);
        my_printf(2, SDLREDN, "pcode = ", opt->pcode);
        my_printf(2, SDLBLUEN, "params = ", opt->params);
        my_printf(2, SDYELLOWN, "param_types = ", opt->param_types);
        opt = opt->next;
    }
}

void opt_push_back(operation_t *opt, operation_t *new)
{
    while (opt->next)
    {
        opt = opt->next;
    }
    opt->next = new;
}
