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

Test(x_min, first)
{
    int a = 1;
    int b = 0;

    cr_assert_eq(x_min(a, b), fmin(a, b));
}

Test(x_min, second)
{
    int a = -1;
    int b = 0;

    cr_assert_eq(x_min(a, b), fmin(a, b));
}

Test(x_mind, first)
{
    double a = 1.2;
    double b = 1.15;

    cr_assert_eq(x_mind(a, b), fmin(a, b));
}

Test(x_mind, second)
{
    double a = -1.2;
    double b = -1.15;

    cr_assert_eq(x_mind(a, b), fmin(a, b));
}

Test(x_minf, first)
{
    float a = -5.256;
    float b = -5.257;

    cr_assert_eq(x_minf(a, b), fminf(a, b));
}

Test(x_minf, second)
{
    float a = 58;
    float b = 58.00001;

    cr_assert_eq(x_minf(a,  b), fminf(a, b));
}


Test(x_minl, first)
{
    long double a = 58.00000000000001;
    long double b = 58.000000000000001;

    cr_assert_eq(x_minl(a, b), fminl(a, b));
}

Test(x_minl, second)
{
    long double a = -58.00000000000001;
    long double b = -58.000000000000001;

    cr_assert_eq(x_minl(a, b), fminl(a, b));
}
