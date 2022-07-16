/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"

Test(x_strsplit, null)
{
    char **arr = x_strsplit(NULL, "k");

    cr_assert_eq(arr, NULL);
}

Test(x_strsplit, one)
{
    char **arr = x_strsplit("one", "\n");

    cr_assert_str_eq(arr[0], "one");
    free(arr[0]);
    cr_assert_eq(arr[1], NULL);
    free(arr);
}

Test(x_strsplit, many)
{
    char **arr = x_strsplit("abd\n\ne", "\n");
    char *res[] = {"abd", "", "e"};

    for (int i = 0; i < 3; i++) {
        cr_assert_str_eq(arr[i], res[i]);
        free(arr[i]);
    }
    cr_assert_eq(arr[4], NULL);
    free(arr);
}
