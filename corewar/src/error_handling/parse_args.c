/*
** EPITECH PROJECT, 2020
** parse_arg.c
** File description:
** parse args
*/

#include "corewar.h"

static const char *flags[3] = {"-dump", "-n", "-a"};

int check_cor_file(char *name)
{
    int len = my_strlen(name);
    int i = 0;

    for (; name[i] ; i++) {
        if (name[i] == '.' && (name[i + 1] != '.' && name[i + 1] != '/'))
            break;
    }
    if (len == i || !my_strcmp(name + i, ".cor")) {
        my_printf(2, "%sError:NameFile: [%s]\n%s", GREEN, name, GREEN);
        return 1;
    }
    return 0;
}

int choice(int i, char **av, parser_t *parser, champ_t *player)
{
    if (!av[i + 1])
        return fill_cor_file(av[i], parser, player);
    if (my_strcmp(av[i], flags[0]))
        return check_value_dump(av[i + 1], parser);
    if (my_strcmp(av[i], flags[1]))
        return check_value_prog(av[i + 1], parser);
    if (my_strcmp(av[i], flags[2]))
        return check_value_adress(av[i + 1], parser);
    return fill_cor_file(av[i], parser, player);
}

parser_t *parser_vm(int ac , char **av, champ_t player[][4])
{
    int i = 1;
    int ret = 0;
    int i_player = 0;
    parser_t *parser = init_parser_t();

    if (!parser)
        return NULL;
    while (i < ac) {
        ret = choice(i, av, parser, &(*player)[i_player]);
        if (ret == -1) {
            return NULL;
        }
        if (ret == 1)
            i_player++;
        i += ret;
    }
    return parser;
}

parser_t *parse_args(int ac, char **av, champ_t tab_player[][4])
{
    parser_t *parser = parser_vm(ac, av, tab_player);

    if (!parser || check_parser_values(parser) == -1 ||
        check_cor_file(av[ac - 1])) {
        my_printf(2, "%sERROR PARSING%s", RED, RED);
        return NULL;
    }
    for (int i = 0; i < parser->nb_players; i++) {
        my_printf(2, "%sPLAYER[%d]:\n\tname = %s%s\n",
        BLUE, i, ((*tab_player) + i)->file_name, DEF);
        my_printf(2, "%s\tchamp_nb = %d%s\n",
        BLUE, (*tab_player)[i].champ_nb, DEF);
        my_printf(2, "%s\tadress = %d%s\n",
        BLUE, ((*tab_player) + i)->champ_pos, DEF);
    }
    return parser;
}
