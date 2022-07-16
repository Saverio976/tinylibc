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

Test(x_strlen, null_s)
{
    int len = x_strlen(NULL);

    cr_assert_eq(len, 0);
}

Test(x_strlen, empty_string)
{
    int len = x_strlen("");

    cr_assert_eq(len, 0);
}

Test(x_strlen, ok)
{
    int len = x_strlen("okig");

    cr_assert_eq(len, 4);
}
