/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcmaths.h"

Test(x_pow, x_1)
{
    cr_assert_eq(x_pow(1, 2), 1);
}

Test(x_pow, y_1)
{
    cr_assert_eq(x_pow(2, 1), 1);
}

Test(x_pow, ok)
{
    cr_assert_eq(x_pow(5, 5), 3125);
}

Test(x_powf, x_1)
{
    cr_assert_eq(x_powf(1, 2), 1);
}

Test(x_powf, y_1)
{
    cr_assert_eq(x_powf(2, 1), 1);
}

Test(x_powf, ok)
{
    cr_assert_eq(x_powf(5, 5), 3125);
}

Test(x_powl, x_1)
{
    cr_assert_eq(x_powl(1, 2), 1);
}

Test(x_powl, y_1)
{
    cr_assert_eq(x_powl(2, 1), 1);
}

Test(x_powl, ok)
{
    cr_assert_eq(x_powl(5, 5), 3125);
}
