/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>
#include "tlcstdios.h"

Test(x_putc, nl, .init=cr_redirect_stdout)
{
    x_putc('c', true);
    cr_assert_stdout_eq_str("c\n");
}

Test(x_putc, nonl, .init=cr_redirect_stdout)
{
    x_putc('c', false);
    cr_assert_stdout_eq_str("c");
}
