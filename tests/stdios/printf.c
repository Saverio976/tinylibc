/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tlcstdios.h"

Test(x_printf, null)
{
    cr_assert_eq(x_printf(NULL), 0);
}

Test(x_printf, ok, .init=cr_redirect_stdout)
{
    x_printf("ok %d %c %s %% %p", 4, 'c', "okidoki", NULL);
    cr_assert_stdout_eq_str("ok 4 c okidoki % (nil)");
}
