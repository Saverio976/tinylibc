/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "tlcstdlibs.h"

Test(x_itoa, zero)
{
    char *str = NULL;

    str = x_itoa(0);
    cr_assert_str_eq(str, "0");
    free(str);
}

Test(x_itoa, neg)
{
    char *str = NULL;

    str = x_itoa(-15);
    cr_assert_str_eq(str, "-15");
    free(str);
}

Test(x_itoa, pos)
{
    char *str = NULL;

    str = x_itoa(500);
    cr_assert_str_eq(str, "500");
    free(str);
}
