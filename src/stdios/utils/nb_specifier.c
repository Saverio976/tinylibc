/*
** EPITECH PROJECT, 2022
** (my) TinyLibC
** File description:
** get string from number
*/

#include <stddef.h>
#include <stdarg.h>
#include "tlcstdlibs.h"
#include "tlcutils.h"

char *i_specifier(va_list ap, UNUSED const char *rest, UNUSED int *index)
{
    int nb = 0;
    char *str = NULL;

    nb = va_arg(ap, int);
    str = x_itoa(nb);
    return (str);
}

char *x_up_specifier(va_list ap, UNUSED const char *rest, UNUSED int *index)
{
    int nb = 0;
    char *str = NULL;

    nb = va_arg(ap, int);
    str = itoa_base(nb, "0123456789ABCDEF");
    return (str);
}

char *x_low_specifer(va_list ap, UNUSED const char *rest, UNUSED int *index)
{
    int nb = 0;
    char *str = NULL;

    nb = va_arg(ap, int);
    str = itoa_base(nb, "0123456789abcdef");
    return (str);
}
