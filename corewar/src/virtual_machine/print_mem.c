/*
** EPITECH PROJECT, 2020
** print_mem
** File description:
** prints the vm memory
*/

#include "corewar.h"

static const int DISP_SIZE = 32;

void show_champ(vm_t *vm, int i, int len, int nb)
{
    unsigned char byte;

    for (; i < len; i++) {
        byte = vm->mem[i];
        (nb == 1) ? my_printf(2, SXRED " ", F16(byte)) : 0;
        (nb == 2) ? my_printf(2, SXBLUE " ", F16(byte)) : 0;
        (nb == 3) ? my_printf(2, SXGREEN " ", F16(byte)) : 0;
        (nb == 4) ? my_printf(2, SXYELLOW " ", F16(byte)) : 0;
    }
}

void print_pcs(vm_t *vm, UNSD champ_t *champ, int i, int nb)
{
    unsigned char byte = vm->mem[i];
    process_t *p = vm->all_process;

    while (p) {
        if (p->pc == i) {
            (nb == 1) ? my_printf(2, SXWHITE " ", F16(byte), byte) : 0;
            (nb == 2) ? my_printf(2, SXRED " ", F16(byte), byte) : 0;
            (nb == 3) ? my_printf(2, SXBLUE " ", F16(byte), byte) : 0;
            (nb == 4) ? my_printf(2, SXGREEN " ", F16(byte), byte) : 0;
        }
        p = p->next;
    }
}

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
