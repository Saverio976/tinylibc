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

Test(x_strncpy, null_dest)
{
    char *dest = NULL;

    dest = x_strncpy(dest, "oki", 2);
    cr_assert_eq(dest, NULL);
}

Test(x_strncpy, null_src)
{
    char *dest = "hello";

    dest = x_strncpy(dest, NULL, 2);
    cr_assert_eq(dest, NULL);
}

Test(x_strncpy, ok)
{
    char dest[] = "hello";

    x_strncpy(dest, "ok", 1);
    cr_assert_str_eq(dest, "oello");
}

Test(x_strncpy, empty_string)
{
    char dest[] = "hello";

    x_strncpy(dest, "", 0);
    cr_assert_str_eq(dest, "hello");
}
