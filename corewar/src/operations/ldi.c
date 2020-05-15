
#include "corewar.h"

int ldi(vm_t *vm, process_t *process)
{
    int a = get_param_value(vm, process, 1);
    int b = get_param_value(vm, process, 2);
    int c = get_param_value(vm, process, 3);
    int param1 = get_param_type(vm, process, 1);
    int param2 = get_param_type(vm, process, 2);
    int param3 = get_param_type(vm, process, 3);


    c == 0 ? process->carry = 1 : 0;
    move_pc(vm, process);
    return 0;
}