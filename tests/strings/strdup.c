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

Test(x_strdup, null_s)
{
    char *new = x_strdup(NULL);

    cr_assert_eq(new, NULL);
}

Test(x_strdup, empty_string)
{
    char *new = x_strdup("");

    cr_assert_str_eq(new, "");
    free(new);
}

Test(x_strdup, ok)
{
    char *new = x_strdup("ok");

    cr_assert_str_eq(new, "ok");
    free(new);
}
