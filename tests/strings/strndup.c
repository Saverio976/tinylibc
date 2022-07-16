/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <stddef.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"

Test(x_strndup, null_s)
{
    char *new = x_strndup(NULL, 1);

    cr_assert_eq(new, NULL);
}

Test(x_strndup, empty_string)
{
    char *new = x_strndup("", 0);

    cr_assert_str_eq(new, "");
    free(new);
}

Test(x_strndup, ok)
{
    char *new = x_strndup("ok", 1);

    cr_assert_str_eq(new, "o");
    free(new);
}

Test(x_strndup, gt)
{
    char *new = x_strndup("k", 3);

    cr_assert_str_eq(new, "k");
    free(new);
}

Test(x_strndup, negativ_n)
{
    char *new = x_strndup("k", -1);

    cr_assert_eq(new, NULL);
}
