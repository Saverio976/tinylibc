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

Test(x_strcpy, null_dest)
{
    char *dest = NULL;

    dest = x_strcpy(dest, "oki");
    cr_assert_eq(dest, NULL);
}

Test(x_strcpy, null_src)
{
    char *dest = "hello";

    dest = x_strcpy(dest, NULL);
    cr_assert_eq(dest, NULL);
}

Test(x_strcpy, ok)
{
    char dest[] = "hello";

    x_strcpy(dest, "ok");
    cr_assert_str_eq(dest, "ok");
}

Test(x_strcpy, empty_string)
{
    char dest[] = "hello";

    x_strcpy(dest, "");
    cr_assert_str_eq(dest, "");
}
