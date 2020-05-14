/*
** EPITECH PROJECT, 2020
** decryt_champ_content.c
** File description:
** decrypt champ content
*/

#include "corewar.h"

int check_direct(char *name)
{
    if (!my_strcmp(name, "zjmp") && !my_strcmp(name, "ldi") &&
        !my_strcmp(name, "fork") && !my_strcmp(name, "sti") &&
        !my_strcmp(name, "lfork") && !my_strcmp(name, "lldi"))
        return DIR_SIZE;
    return IND_SIZE;
}

static void decrypt_params(int byte, char **buf, int *read_len, unsigned char code)
{
    unsigned char value;
    int           result;
    char          *temp = *buf + 1;

    if (byte == 1)
        my_printf(2, SRED, "REG ");
    else if (byte == 2)
        my_printf(2, SRED, "DIR ");
    else
        my_printf(2, SRED, "IND ");
    my_printf(2, "%ssize:%s%d  %s", GREEN, BOLD, byte, DEF);
    result = read_nbytes(&temp, byte, code);
    my_printf(2, DLBLUE"  ", result);
    for (ssize_t i = 0; i != byte; i++)
    {
        (*read_len)--;
        (*buf)++;
        value = **buf;
        my_printf(2, SBLUE XBLUE"  ", (value < 16) ? "0" : "", value);
    }
    my_printf(2, "\n");
}

static bool decrypt_name(unsigned char value)
{
    int  code = value;
    char *name = OTM(code - 1);
    int  typed = is_typed(code - 1);

    my_printf(2, BOLD SWHITE" | ", name);
    my_printf(2, SMAGENTAN, typed ? "true" : "false");
    if (typed)
        return true;
    return false;
}

static int decrypt_type(unsigned char value, int params[][4], int code, bool typed)
{
    int type = value;
    int temp = 0;

    if (!typed)
    {
        (*params)[0] = check_direct(OTM(code - 1));
        return 0;
    }
    my_printf(2, SYELLOW DLYELLOWN, "type = ", type);
    for (ssize_t i = 0; i != 4; i++)
    {
        temp = type >> (2 * i);
        temp &= 0x03;
        if (temp == 2)
            (*params)[3 - i] = check_direct(OTM(code - 1));
        else
            (*params)[3 - i] = temp;
    }
    return type;
}

void decrypt_instruction(unsigned char code, char **buf, int *read_len, operation_t *opt)
{
    int  params[4] = {0};
    bool typed = false;

    if (decrypt_name(code))
    {
        (*read_len)--;
        (*buf)++;
        typed = true;
    }
    opt->param_types = decrypt_type(**buf, &params, code, typed);
    my_printf(2, SLGREENN, "params━━━━━━━━━━━━━━━━━━━");
    for (ssize_t i = 0; params[i]; i++)
        decrypt_params(params[i], buf, read_len, code);
}
