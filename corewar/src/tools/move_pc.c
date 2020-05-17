/*
** EPITECH PROJECT, 2020
** move_pc
** File description:
** moves the pc
*/

#include "corewar.h"

void move_pc(vm_t *vm, process_t *process)
{
    int tmp_pc = get_next_pc(vm, process);
    int new_pos = tmp_pc + process->pc;

    if (new_pos >= 0)
        new_pos %= MEM_SIZE;
    else
        new_pos = (new_pos % MEM_SIZE) + MEM_SIZE;
    process->pc = new_pos;
}
