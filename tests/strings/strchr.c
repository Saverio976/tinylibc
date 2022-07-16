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

Test(x_strchr, null_str)
{
    char *res = x_strchr(NULL, 'c');

    cr_assert_eq(res, NULL);
}

Test(x_strchr, zero_char)
{
    char *res = x_strchr("ggg", '\0');

    cr_assert_eq(res, NULL);
}

Test(x_strchr, ok_mid)
{
    const char tab[] = "azerty";
    char *res = x_strchr(tab, 'e');

    cr_assert_eq(res, tab + 2);
}

Test(x_strchr, ok_start)
{
    const char tab[] = "azerty";
    char *res = x_strchr(tab, 'a');

    cr_assert_eq(res, tab);
}

Test(x_strchr, ok_end)
{
    const char tab[] = "azerty";
    char *res = x_strchr(tab, 'y');

    cr_assert_eq(res, tab + 5);
}
