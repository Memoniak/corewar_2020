/*
** EPITECH PROJECT, 2020
** print_mem
** File description:
** prints the vm memory
*/

#include "corewar.h"

static const int DISP_SIZE = 64;
#define F16(a)    ((a < 16) ? "0" : "")

void show_champ(vm_t *vm, int i, int len, int nb)
{
    unsigned char byte;

    for (; i < len; i++) {
        byte = vm->mem[i];
        (nb == 1) ? my_printf(2, SXRED " ",
        (byte < 16) ? "0" : "", byte) : 0;
        (nb == 2) ? my_printf(2, SXBLUE " ",
        (byte < 16) ? "0" : "", byte) : 0;
        (nb == 3) ? my_printf(2, SXGREEN " ",
        (byte < 16) ? "0" : "", byte) : 0;
        (nb == 4) ? my_printf(2, SXYELLOW " ",
        (byte < 16) ? "0" : "", byte) : 0;
    }
}

void print_pcs(vm_t *vm, UNSD champ_t *champ, int i, int nb)
{
    unsigned char byte = vm->mem[i];
    process_t *p = vm->all_process;

    while (p) {
        if (p->pc == i) {
            (nb == 1) ? my_printf(2, SXWHITE " ",
            (byte < 16) ? "0" : "", byte) : 0;
            (nb == 2) ? my_printf(2, SXRED " ",
            (byte < 16) ? "0" : "", byte) : 0;
            (nb == 3) ? my_printf(2, SXBLUE " ",
            (byte < 16) ? "0" : "", byte) : 0;
            (nb == 4) ? my_printf(2, SXGREEN " ",
            (byte < 16) ? "0" : "", byte) : 0;
        }
        p = p->next;
    }
}

void print_mem(vm_t *vm)
{
    unsigned char byte;

    for (int i = 0; i < MEM_SIZE; i++) {
        byte = vm->mem[i];
        if (i == vm->all_process->pc)
            my_printf(2, FBG SXRED " ", F16(byte), byte);
        else if (i > vm->champ->prog_size)
           my_printf(2, DARK SXWHITE " ", F16(byte), byte);
        else
            my_printf(2, SXRED " ", F16(byte), byte);
        if (!((i + DISP_SIZE + 1) % DISP_SIZE))
            my_printf(2, "\n");
    }
}
