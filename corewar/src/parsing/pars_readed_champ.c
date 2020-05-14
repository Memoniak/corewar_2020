/*
** EPITECH PROJECT, 2020
** pars_readed_champ.c
** File description:
** pars the raeded buf
*/

#include "corewar.h"

static void pars_header(int move, char *buf, champ_t *champ)
{
    if (move == 4)
    {
        get_prog_name(&buf, &champ->name);
        my_printf(2, BOLD SLBLACK SLWHITEN, ".name   = ", champ->name);
    }
    if (move == 8 + PROG_NAME_LENGTH)
    {
        get_prog_size(&buf, &champ->prog_size);
        my_printf(2, BOLD SLBLACK DLWHITEN, ".size   = ", champ->prog_size);
    }
    if (move == 12 + PROG_NAME_LENGTH)
    {
        get_prog_comment(&buf, &champ->comment);
        my_printf(2, BOLD SLBLACK SLWHITEN, ".comment= ", champ->comment);
    }
}

static void pars_loop(char *buf, int read_len, champ_t *champ, operation_t *opt)
{
    int move = 0;

    while (read_len--)
    {
        pars_header(move, buf, champ);
        if (read_len == champ->prog_size - 1)
            champ->prog = my_strndup(champ->prog, buf, champ->prog_size);
        if (read_len < champ->prog_size)
        {
            opt->code = *buf;
            opt->index = (champ->prog_size - read_len - 1);
            opt->nb_cycles = op_tab[opt->code - 1].nbr_cycles;
            my_printf(2, STEALN, "━━━━━━━━━━━");
            my_printf(2, SXLTEAL" | ", "code = ", *buf);
            my_printf(2, SDLMAGENTAN, "index = ", (champ->prog_size - read_len - 1));
            decrypt_instruction(*buf, &buf, &read_len, opt);
            opt->next = opt_create();
            opt = opt->next;
        }
        move++;
        buf++;
    }
}

void pars_all_values(char *buf, int read_len, champ_t *champ, operation_t *opt)
{
    int magic = get_nbytes(&buf, 4);

    if (magic != COREWAR_EXEC_MAGIC)
    {
        my_printf(2, "%sError with Magic Number:%s%s %d != %d%s\n",
                  RED, BOLD, WHITE, magic, COREWAR_EXEC_MAGIC, DEF);
        exit(EXIT_FAILURE);
    }
    my_printf(2, BOLD SLBLACK XLWHITEN, ".magic  = ", magic);
    pars_loop(buf, read_len, champ, opt);
}
