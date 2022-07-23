/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include <stdbool.h>
#include "tlcstdios.h"

Test(x_puts, null)
{
    cr_assert_eq(x_puts(NULL, false), 0);
}

Test(x_puts, nl, .init=cr_redirect_stdout)
{
    x_puts("oki", true);
    cr_assert_stdout_eq_str("oki\n");
}

Test(x_puts, nonl, .init=cr_redirect_stdout)
{
    x_puts("doki", false);
    cr_assert_stdout_eq_str("doki");
}

