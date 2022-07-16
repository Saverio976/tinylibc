/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <stddef.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"

Test(x_strstr, null_str)
{
    char *res = x_strstr(NULL, "cd");

    cr_assert_eq(res, NULL);
}

Test(x_strstr, zero_char)
{
    char *res = x_strstr("ggg", "");

    cr_assert_eq(res, NULL);
}

Test(x_strstr, ok_mid)
{
    const char tab[] = "azerty";
    char *res = x_strstr(tab, "er");

    cr_assert_eq(res, tab + 2);
}

Test(x_strstr, ok_start)
{
    const char tab[] = "azerty";
    char *res = x_strstr(tab, "aze");

    cr_assert_eq(res, tab);
}

Test(x_strstr, ok_end)
{
    const char tab[] = "azerty";
    char *res = x_strstr(tab, "rty");

    cr_assert_eq(res, tab + 3);
}
