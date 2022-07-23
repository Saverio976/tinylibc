/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>
#include "tlcstdios.h"

Test(x_sprintf, null)
{
    cr_assert_eq(x_sprintf(NULL), NULL);
}

Test(x_sprintf, d)
{
    char *str = NULL;

    str = x_sprintf("%d%i %d", 5, 10, 0);
    cr_assert_str_eq(str, "510 0");
    free(str);
}

Test(x_sprintf, c)
{
    char *str = NULL;

    str = x_sprintf("%c%c %c", 'o', 'k', '4');
    cr_assert_str_eq(str, "ok 4");
    free(str);
}

Test(x_sprintf, s)
{
    char *str = NULL;

    str = x_sprintf("%s%s %s", "ok", "ko", "llm");
    cr_assert_str_eq(str, "okko llm");
    free(str);
}

Test(x_sprintf, x)
{
    char *str = NULL;

    str = x_sprintf("%x%X %x", 10, 11, 2);
    cr_assert_str_eq(str, "0xa0XB 0x2");
    free(str);
}

Test(x_sprintf, ptr)
{
    char *str = NULL;

    str = x_sprintf("%p%p, %p", (void *) 0, (void *) 1, (void *) 2);
    cr_assert_str_eq(str, "(nil)0x1, 0x2");
    free(str);
}

Test(x_sprintf, mod)
{
    char *str = NULL;

    str = x_sprintf("%%%%, %%");
    cr_assert_str_eq(str, "%%, %");
    free(str);
}

Test(x_sprintf, nothing)
{
    char *str = NULL;

    str = x_sprintf("oki doki !!");
    cr_assert_str_eq(str, "oki doki !!");
    free(str);
}

Test(x_vsprintf, null)
{
    va_list ap;

    cr_assert_eq(x_vsprintf(NULL, ap), NULL);
}
