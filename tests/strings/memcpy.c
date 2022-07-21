/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcllists.h"
#include "tlcstrings.h"

Test(x_memcpy, ok)
{
    node_result_t n1 = {.node_ptr = (void *) 1, .node_index = 2};
    node_result_t new = {0};
    void *res = NULL;

    res = x_memcpy(&new, &n1, sizeof(node_result_t));
    cr_assert_eq(new.node_index, n1.node_index);
    cr_assert_eq(new.node_ptr, n1.node_ptr);
    cr_assert_neq(res, NULL);
}

Test(x_memcpy, src_null)
{
    int a = 5;
    void *res = NULL;

    res = x_memcpy(&a, NULL, sizeof(int));
    cr_assert_eq(res, NULL);
}

Test(x_memcpy, dest_null)
{
    int a = 5;
    void *res = NULL;

    res = x_memcpy(NULL, &a, sizeof(int));
    cr_assert_eq(res, NULL);
}
