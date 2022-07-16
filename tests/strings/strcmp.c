/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <stddef.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"

Test(x_strcmp, null_s1)
{
    int res = x_strcmp(NULL, "ok");

    cr_assert_lt(res, 0);
}

Test(x_strcmp, null_s2)
{
    int res = x_strcmp("ok", NULL);

    cr_assert_gt(res, 0);
}

Test(x_strcmp, empty_string_s1)
{
    int res = x_strcmp("", "ok");

    cr_assert_lt(res, 0);
}

Test(x_strcmp, empty_string_s2)
{
    int res = x_strcmp("ok", "");

    cr_assert_gt(res, 0);
}

Test(x_strcmp, s1_s2_equall_empty)
{
    int res = x_strcmp("", "");

    cr_assert_eq(res, 0);
}

Test(x_strcmp, s1_s2_equall)
{
    int res = x_strcmp("okidoki", "okidoki");

    cr_assert_eq(res, 0);
}
