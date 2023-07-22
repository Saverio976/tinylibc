/*
** EPITECH PROJECT, 2022
** (my) TinyLibC
** File description:
** return a pointer to string exa
*/

#include <stddef.h>
#include <stdarg.h>
#include "tlcstdlibs.h"
#include "tlcstrings.h"
#include "tlcutils.h"
#include "utils.h"

static const size_t size_max = 30;

char *ptrtohexa(void *ptr, const char *base_16)
{
    int i = 0;
    char *result = x_calloc(size_max);
    long int nb = (long int) ptr;

    if (result == NULL || ptr == NULL || x_strlen(base_16) != 16) {
        return ((ptr == NULL) ? x_strcpy(result, "(nil)") : NULL);
    }
    for (; nb > 0; i++) {
        result[i] = base_16[nb % 16];
        nb /= 16;
    }
    result[i++] = (base_16[15] == 'F') ? 'X' : 'x';
    result[i++] = '0';
    result = x_strrev(result);
    return (result);
}

char *ptr_specifier(va_list ap, UNUSED const char *res, UNUSED size_t *index)
{
    void *ptr = NULL;
    char *str = NULL;

    ptr = va_arg(ap, void *);
    str = ptrtohexa(ptr, "0123456789abcdef");
    return (str);
}
