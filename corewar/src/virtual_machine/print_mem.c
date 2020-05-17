/*
** EPITECH PROJECT, 2020
** print_mem
** File description:
** prints the vm memory
*/

#include "corewar.h"

static const int DISP_SIZE = 64;

static int disp_all_pc(vm_t *vm, int i)
{
    process_t *proc = vm->all_process;

    while (proc)
    {
        if (i == proc->pc)
            return proc->id;
        proc = proc->next;
    }
    return -1;
}

static void two_champions(vm_t *vm)
{
    unsigned char byte;
    int temp = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        byte = vm->mem[i];
        temp = disp_all_pc(vm, i);
        if (temp >= 0)
            my_printf(2, FBG SXYELLOW" ", F16(byte), byte);
        else if ((i >= vm->champ[0].prog_size && i < vm->champ[1].champ_pos) ||
        i >= vm->champ[1].prog_size + vm->champ[1].champ_pos)
            my_printf(2, SXLBLACK " ", F16(byte), byte);
        else {
            if (i < vm->champ[0].prog_size)
                my_printf(2, BOLD SXRED " ", F16(byte), byte);
            else
                my_printf(2, BOLD SXGREEN " ", F16(byte), byte);
        }
        if (!((i + DISP_SIZE + 1) % DISP_SIZE))
            my_printf(2, "\n");
    }
}

void print_mem(vm_t *vm)
{
    unsigned char byte;
    int temp = 0;

    if (vm->nb_champs == 2)
    {
        two_champions(vm);
        return;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        byte = vm->mem[i];
        temp = disp_all_pc(vm, i);
        if (temp >= 0)
            my_printf(2, FBG SXYELLOW " ", F16(byte), byte);
        else if (i >= vm->champ[0].prog_size)
            my_printf(2, SXLBLACK " ", F16(byte), byte);
        else
            my_printf(2, BOLD SXRED " ", F16(byte), byte);
        if (!((i + DISP_SIZE + 1) % DISP_SIZE))
            my_printf(2, "\n");
    }
}
