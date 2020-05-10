/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** prints stuff
*/

#include "printf.h"
#include <unistd.h>

static const args_t fct[10] = {
    {"i", (char * (*)())&my_put_nbr},
    {"d", (char * (*)())&my_put_nbr},
    {"u", (char * (*)())&my_put_nbr},
    {"S", (char * (*)())&non_p_s},
    {"s", (char * (*)())&my_putstr_b},
    {"c", (char * (*)())&my_putchar_b},
    {"b", (char * (*)())&to_binary},
    {"x", (char * (*)())&conv_hexa},
    {"o", (char * (*)())&conv_octal},
    {"X", (char * (*)())&conv_hexa_c}};

char *check_arg(string_t str, args_t const *fct, va_list ap, pad_t pad)
{
    char tmp[1] = {str.s};
    char *cpy;
    int c = 0;

    for (int j = 0; j != 10; j++) {
        if (str.s == fct[j].arg[0]) {
            str.buff = my_strcat(str.buff, fct[j].ptr(va_arg(ap, void *)));
            c = 1;
        }
    }
    if (my_strlen(str.buff) < pad.padding[1] + my_strlen(str.buff)) {
        if (pad.checker == '0') {
            cpy = my_strdup(str.buff);
            str.buff = add_padding(str.buff, cpy, pad.padding[1], pad.old_len);
        }
    }
    if (str.s != '#' && c == 0) {
        str.buff = my_strcat(str.buff, "%");
        str.buff = my_strcat(str.buff, tmp);
    }
    return str.buff;
}

int f_arg_checker(char *s, int i, int c_0)
{
    if ((s[i] == '%' && s[i + 1] != '%')
        && ((s[i + 1] != ' ' && s[i + 2] != '0' && c_0 != 0)
            || (s[i + 1] != '0')) || c_0 == 1)
        return 1;
    else
        return 0;
}

int mod_checker(char *s, int i)
{
    if (s[i] == '%' && s[i + 1] == '%')
        i++;
    return i;
}

char *printf_loop(char *s, va_list ap, string_t str, flag_t flags)
{
    for (int i = 0; s[i] != '\0'; i++) {
        flags.pad_s.old_len = my_strlen(str.buff);
        if (f_arg_checker(s, i, flags.c_0)) {
            flags.flag = check_flags(s[i + 1], i + 1, s, str.buff);
            i += flags.flag;
            str.buff = flag_true(str.buff, flags.flag, s, i);
            str.s = s[i + 1];
            check_arg(str, fct, ap, flags.pad_s);
            flags.pad_s.padding = init_padded_num();
            flags.c_0 = 0;
            i++;
        } else if ((s[i + 1] == '0' || s[i + 1] == ' ') && s[i] == '%') {
            flags.pad_s.padding = get_padded_nb(s, i, fct);
            i += flags.pad_s.padding[0] - 2;
            flags.c_0 = 1;
        } else
            str.buff[flags.pad_s.old_len] = s[i];
        i = mod_checker(s, i);
    }
    return str.buff;
}

int my_printf(char *s, ...)
{
    va_list ap;
    string_t str;
    flag_t flags = { 0, 0, 0, 0};

    str.buff = init_buffer();
    flags.pad_s.padding = init_padded_num();
    flags.pad_s.checker = '0';
    flags.pad_s.old_len = 0;
    va_start(ap, s);
    str.buff = printf_loop(s, ap, str, flags);
    my_putstr(str.buff);
    va_end(ap);
    return my_strlen(str.buff);
}
