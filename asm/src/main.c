/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for asm
*/

#include "corewar.h"

UNSD static void display_funct(funct_t *funct)
{
    for (int i = 0; i < funct[0].len; i++) {
//        my_printf(2, "%sfunc name --> %s%s\n", BLUE, funct[i].name, DEF);
        for (int j = 0; j < funct[i].nb_cmd; j++) {
//            my_printf(2, "%scommand:\n\tindex:%i\n\tcode:%i"
//                      "\n\tparam1:%s\n\tparam2:%s\n\tparam3:%s"
//                      "\n\tparam4:%s%s\n", YELLOW, funct[i].commands[j].index,
//                      funct[i].commands[j].code, funct[i].commands[j].param1,
//                      funct[i].commands[j].param2, funct[i].commands[j].param3,
//                      funct[i].commands[j].param4, DEF);
        }
    }
}

static int find_usage(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        my_printf(1, "USAGE\n./asm file_name[.s]\nDESCRITPION\n");
        my_printf(1, "file_name file in assembly language to be converted");
        my_printf(1, "into file_name.cor, an executable in the Virtual");
        my_printf(1, " Machine.\n");
        return 1;
    }
    return 0;
}

int check_filepath(char *filepath)
{
    int pos = get_pos_word_in_str(".s", filepath);

    if (pos == -1)
        return 0;
    return 1;
}

int main(int ac, char **av)
{
    champion_header_t champ = {0};
    funct_t *funct = NULL;

    if (ac != 2 || !check_filepath(av[1]))
        return EXIT_FAILURE;
    if (find_usage(ac, av))
        return EXIT_SUCCESS;
    if (!(funct = make_struct(av[1], &champ))) {
        destroy_all(funct, &champ);
        return EXIT_FAILURE;
    } if (check_errors_instructions(funct)) {
        destroy_all(funct, &champ);
        return EXIT_FAILURE;
    } if (!sim_main(funct, champ.file_name, &champ)) {
        destroy_all(funct, &champ);
        return EXIT_FAILURE;
    }
    destroy_all(funct, &champ);
    return EXIT_SUCCESS;
}
