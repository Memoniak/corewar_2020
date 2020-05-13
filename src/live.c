/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include

static int champ_alive(champ_t *champion, vm_t *vm)
{
    vm->cycle_to_die = -1;
    vm->nb_live++;
    vm->current_champ = champion;
//    while (*str != '.' && *str)
    my_printf(1, "The player %d(%s)is alive.\n", champion->champ_nb, champion->name); //avant le %s y'a un truc ?? et str ou str++ ??
    return 0;
}

int live(champ_t *champion, vm_t *vm)
{
    champ_t *tmp;
    char flag;

    if (champion->/*nb de champ, max de champ*/[0] == champion->process->registre[0]
       || champion->process->registre[0])
        return (do_live(champion, vm));
    else {
        tmp = champion->process->next;
        while (tmp != champion) {
            if (champion->/*nb de champ, max de champ*/ == tmp->process->registre[0])
                do_live(tmp, vm);
            tmp = tmp->process->next;
        }
    }
    return 0;
}
/*
int main()
{
    }*/
