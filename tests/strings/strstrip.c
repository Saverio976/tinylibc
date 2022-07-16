/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"

Test(x_strstrip, null)
{
    char *new = x_strstrip(NULL, "k");

    cr_assert_eq(new, NULL);
}

Test(x_strstrip, one_char)
{
    char *new = x_strstrip("o", "o");

    cr_assert_str_eq(new, "");
    free(new);
}

Test(x_strstrip, ok_start)
{
    char *new = x_strstrip("obt", "o");

    cr_assert_str_eq(new, "bt");
    free(new);
}

Test(x_strstrip, ok_end)
{
    char *new = x_strstrip("obt", "t");

    cr_assert_str_eq(new, "ob");
    free(new);
}

Test(x_strstrip, ok_both)
{
    char *new = x_strstrip("obt", "obt");

    cr_assert_str_eq(new, "");
    free(new);
}
