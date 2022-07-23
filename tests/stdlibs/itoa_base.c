/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "tlcstdlibs.h"

Test(itoa_base, zero)
{
    char *str = NULL;

    str = itoa_base(0, "ABCDEF");
    cr_assert_str_eq(str, "A");
    free(str);
}

Test(itoa_base, neg)
{
    char *str = NULL;

    str = itoa_base(-15, "0123456789ABCDEF");
    cr_assert_str_eq(str, "-F");
    free(str);
}

Test(itoa_base, pos)
{
    char *str = NULL;

    str = itoa_base(500, "01");
    cr_assert_str_eq(str, "111110100");
    free(str);
}
