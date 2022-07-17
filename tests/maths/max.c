/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <math.h>
#include "tlcmaths.h"

Test(x_max, first)
{
    int a = 1;
    int b = 0;

    cr_assert_eq(x_max(a, b), fmax(a, b));
}

Test(x_max, second)
{
    int a = -1;
    int b = 0;

    cr_assert_eq(x_max(a, b), fmax(a, b));
}

Test(x_maxd, first)
{
    double a = 1.2;
    double b = 1.15;

    cr_assert_eq(x_maxd(a, b), fmax(a, b));
}

Test(x_maxd, second)
{
    double a = -1.2;
    double b = -1.15;

    cr_assert_eq(x_maxd(a, b), fmax(a, b));
}

Test(x_maxf, first)
{
    float a = -5.256;
    float b = -5.257;

    cr_assert_eq(x_maxf(a, b), fmaxf(a, b));
}

Test(x_maxf, second)
{
    float a = 58;
    float b = 58.00001;

    cr_assert_eq(x_maxf(a,  b), fmaxf(a, b));
}


Test(x_maxl, first)
{
    long double a = 58.00000000000001;
    long double b = 58.000000000000001;

    cr_assert_eq(x_maxl(a, b), fmaxl(a, b));
}

Test(x_maxl, second)
{
    long double a = -58.00000000000001;
    long double b = -58.000000000000001;

    cr_assert_eq(x_maxl(a, b), fmaxl(a, b));
}
