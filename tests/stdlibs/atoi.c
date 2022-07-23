/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstdlibs.h"

Test(x_atoi, null)
{
    cr_assert_eq(x_atoi(NULL), 0);
}

Test(x_atoi, ok_neg)
{
    cr_assert_eq(x_atoi("-10"), -10);
}

Test(x_atoi, ok_pos)
{
    cr_assert_eq(x_atoi("505"), 505);
}
