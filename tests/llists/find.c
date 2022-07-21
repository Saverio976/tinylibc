/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdbool.h>
#include "tlcstrings.h"
#include "tlcllists.h"

Test(list_find_ptrdata, null)
{
    list_t *list = NULL;
    node_result_t node = {0};

    node = list_find_ptrdata(list, NULL);
    cr_assert_eq(node.node_index, -1);
    cr_assert_eq(node.node_ptr, NULL);
}

Test(list_find_ptrdata, ok)
{
    list_t *list = NULL;
    node_result_t node = {0};

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    node = list_find_ptrdata(list, NULL);
    cr_assert_eq(node.node_ptr, FIRST(list));
    cr_assert_eq(node.node_index, 0);
}

Test(list_find_ptrdata, not_found)
{
    list_t *list = NULL;
    node_result_t node = {0};

    list = list_append(list, NULL, NULL, NULL);
    node = list_find_ptrdata(list, (void *) 1);
    cr_assert_eq(node.node_ptr, NULL);
    cr_assert_eq(node.node_index, -1);
}

Test(list_find_ptrnode, null)
{
    list_t *list = NULL;
    int node = 0;

    node = list_find_ptrnode(list, NULL);
    cr_assert_eq(node, -1);
}

Test(list_find_ptrnode, ok)
{
    list_t *list = NULL;
    int node = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    node = list_find_ptrnode(list, FIRST(list));
    cr_assert_eq(node, 0);
}

Test(list_find_ptrnode, not_found)
{
    list_t *list = NULL;
    int node = 0;

    list = list_append(list, NULL, NULL, NULL);
    node = list_find_ptrnode(list, NULL);
    cr_assert_eq(node, -1);
}

bool compare(void *s1, void *s2)
{
    if (x_strcmp(s1, s2) == 0) {
        return (true);
    }
    return (false);
}

Test(list_find_f, null)
{
    list_t *list = NULL;
    node_result_t node = {0};

    node = list_find_f(list, compare, NULL);
    cr_assert_eq(node.node_index, -1);
    cr_assert_eq(node.node_ptr, NULL);
}

Test(list_find_f, ok)
{
    list_t *list = NULL;
    node_result_t node = {0};

    list = list_create();
    list = list_append(list, "bh", NULL, NULL);
    list = list_append(list, "ok", NULL, NULL);
    cr_assert_eq(LEN(list), 2);
    node = list_find_f(list, compare, "ok");
    cr_assert_eq(node.node_ptr, NEXT(FIRST(list)));
    cr_assert_eq(node.node_index, 1);
}

Test(list_find_f, not_found)
{
    list_t *list = NULL;
    node_result_t node = {0};

    list = list_append(list, "hh", NULL, NULL);
    node = list_find_f(list, compare, "bg");
    cr_assert_eq(node.node_ptr, NULL);
    cr_assert_eq(node.node_index, -1);
}
