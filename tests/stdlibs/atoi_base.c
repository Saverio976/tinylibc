/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstdlibs.h"

Test(atoi_base, null)
{
    cr_assert_eq(atoi_base(NULL, "01234"), 0);
}

Test(atoi_base, ok_neg)
{
    cr_assert_eq(atoi_base("-A", "0123456789ABCDEF"), -10);
}

Test(x_atoi, ok_pos)
{
    cr_assert_eq(atoi_base("41", "0123456789ABCDEF"), 65);
}
