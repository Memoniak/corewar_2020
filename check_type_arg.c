#include "op.h"
#include <stdio.h>
#include <stdlib.h>

// ! check si register type et pas de registre trop grand
// ? differencier pas reg et reg trop grand

static int check_t_reg(char *param)
{
    int nb_reg;

    if(param[0] != 'r')
        return 1;
    for(int i = 0; param[i]; i++) {
        if (isnum(param[i]))
            return 1;
    }
    my_getnbr(param + 1);
    if (nb_reg > REG_NUMBER)
        return 1;
}

static int check_t_dir(char *param)
{
    if(param[0] != DIRECT_CHAR)
        return 1;
    return 0;
}

static int check_t_ind(char *param)
{
    if(param[0] != LABEL_CHAR)
        return 1;
    return 0;
}

// ! check le type de donnée et return le code de la donnée ou 0 si aucun

int check_type_arg(char *param)
{
    if (!param)
        return 0;
    if (!check_t_reg(param))
        return T_REG;
    if (!check_t_dir(param))
        return T_DIR;
    if (!check_t_ind(param))
        return T_IND;
    return 0;

}