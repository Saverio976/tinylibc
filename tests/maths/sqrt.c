/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcmaths.h"

Test(x_sqrt, x_inf_1)
{
    cr_assert_eq(x_sqrt(0), 0);
}

Test(x_sqrt, ok)
{
    cr_assert_eq(x_sqrt(25), 5);
}

Test(x_sqrtf, x_inf_1)
{
    cr_assert_eq(x_sqrtf(0), 0);
}

Test(x_sqrtf, ok)
{
    cr_assert_eq(x_sqrtf(36), 6);
}

Test(x_sqrtl, x_inf_1)
{
    cr_assert_eq(x_sqrtl(0), 0);
}

Test(x_sqrtl, ok)
{
    cr_assert_eq(x_sqrtl(49), 7);
}
