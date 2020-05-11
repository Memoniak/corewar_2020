/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for asm
*/

#include "corewar.h"

//TODO: fonction auxiliaire parcourir funct et check_instruction

static void display_funct(funct_t *funct)
{
    for (int i = 0; i < funct[0].len; i++) {
	my_printf(2, "%sfunc name --> %s%s\n", BLUE, funct[i].name, DEF);
	for (int j = 0; j < funct[i].nb_cmd; j++) {
	    my_printf(2, "%scommand:\n\tindex:%i\n\tcode:%i\n\tparam1:%s\n\tparam2:%s"
		      "\n\tparam3:%s\n\tparam4:%s%s\n", YELLOW, funct[i].commands[j].index,
		   funct[i].commands[j].code, funct[i].commands[j].param1,
		   funct[i].commands[j].param2, funct[i].commands[j].param3,
		      funct[i].commands[j].param4, DEF);
	}
    }
}

int main(int ac, char **av)
{
    champion_header_t champ = {0};
    funct_t *funct;

    if (ac != 2)
	return EXIT_FAILURE;
    if (!(funct = make_struct(av[1], &champ))) {
	destroy_all(funct, &champ);
	return EXIT_FAILURE;
    }
    if (check_errors_instructions(funct))
	return EXIT_FAILURE;
    if (!sim_main(funct, champ.file_name, &champ)) {
	destroy_all(funct, &champ);
	return EXIT_FAILURE;
    }
    display_funct(funct);
    destroy_all(funct, &champ);
    return EXIT_SUCCESS;
}
