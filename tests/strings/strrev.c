/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <stddef.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"

Test(x_strrev, null)
{
    cr_assert_eq(x_strrev(NULL), NULL);
}

Test(x_strrev, baba)
{
    char tab_rep[] = "abab";
    char tab_o[] = "baba";

    cr_assert_str_eq(x_strrev(tab_o), tab_rep);
}

Test(x_strrev, babao)
{
    char tab_rep[] = "oabab";
    char tab_o[] = "babao";

    cr_assert_str_eq(x_strrev(tab_o), tab_rep);
}
