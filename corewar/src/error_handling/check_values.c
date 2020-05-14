#include "corewar.h"

int check_parser_values(parser_t *parser)
{
    my_printf(2, "nb_dump = %d nb_n = %d nb_a = %d\n", parser->nb_dump, parser->nb_n, parser->nb_a);
    if (parser->nb_a > parser->nb_players ||
        parser->nb_dump > 1 || parser->nb_n > parser->nb_players) {
        my_printf(2, "%sError:NbArguments\n%s", GREEN, GREEN);
        return -1;
    }
    return 0;
}

int fill_cor_file(char *name, parser_t *parser, champ_t *player)
{

    if (check_cor_file(name))
        return -1;
    printf("NAME = %s\n", name);
    if (parser->last_n != parser->nb_players)
        player->champ_nb = parser->last_n;
    //TODO : regler l'histoire des prog number avec le plus petit libre
    player->champ_pos = parser->last_a;
    player->file_name = my_strdup(name);
    parser->last_a = 0;
    parser->nb_players++;
    parser->last_n = parser->nb_players + 1;
    return 1;
}

int check_value_prog(char *name, parser_t *parser)
{
    if (is_num(name[0]) == 0) {
        my_printf(2, "%sError:Arg-n: [%s]\n%s", GREEN, name, GREEN);
        return -1;
    }
    for (size_t i = 1; name[i]; i++) {
        if (is_num(name[0]) != 1) {
            my_printf(2, "%sError:Arg-n: [%s]\n%s", GREEN, name, GREEN);
            return -1;
        }
    }
    parser->last_n = my_getnbr(name);
    //if lasts player == champ_nb augmenter de 1 le champ nb des lasts en ?
    parser->nb_n++;
    return 2;
}

int check_value_adress(char *name, parser_t *parser)
{
    if (is_num(name[0]) == 0) {
        my_printf(2, "%sError:Arg-n: [%s]\n%s", GREEN, name, DEF);
        return -1;
    }
    for (size_t i = 1; name[i]; i++) {
        if (is_num(name[0]) != 1) {
            my_printf(2, "%sError:Arg-n: [%s]\n%s", GREEN, name, DEF);
            return -1;
        }
    }
    parser->last_a = my_getnbr(name) % MEM_SIZE;
    parser->nb_a++;
    return 2;
}

int check_value_dump(char *name, parser_t *parser)
{
    if (is_num(name[0]) == 0) {
        my_printf(2, "%sError:Arg-dump: [%s]\n%s", GREEN, name, GREEN);
        return -1;
    }
    for (size_t i = 1; name[i]; i++) {
        if (is_num(name[0]) != 1) {
            my_printf(2, "%sError:Arg-dump: [%s]\n%s", GREEN, name, GREEN);
            return -1;
        }
    }
    //TODO: check si dumpis ok
    parser->dump = my_getnbr(name);
    parser->nb_dump++;
    return 2;
}