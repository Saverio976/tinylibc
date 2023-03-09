/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcllists.h"

Test(list_insert, null)
{
    list_t *list = NULL;
    node_t *node = NULL;

    node = node_create(NULL, NULL, NULL);
    list = list_insert(list, node, 4);
    cr_assert_eq(list, NULL);
}

Test(list_insert, start)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    node = node_create("ok", NULL, NULL);
    list = list_insert(list, node, 0);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
    cr_assert_eq((list->end)->data, NULL);
    cr_assert_eq(list->len, 2);
}

Test(list_insert, end)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    node = node_create("ok", NULL, NULL);
    list = list_insert(list, node, 1);
    cr_assert_eq((list->start)->data, NULL);
    cr_assert_str_eq((list->end)->data, "ok");
    cr_assert_eq(list->len, 2);
}

Test(list_insert_start, null)
{
    list_t *list = NULL;
    node_t *node = NULL;

    node = node_create(NULL, NULL, NULL);
    list = list_insert_start(list, node);
    cr_assert_eq(list, NULL);
}

Test(list_insert_start, empty)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    node = node_create("ok", NULL, NULL);
    list = list_insert_start(list, node);
    cr_assert_eq(list->len, 1);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
}

Test(list_insert_start, one)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    node = node_create("ok", NULL, NULL);
    list = list_insert_start(list, node);
    cr_assert_eq(list->len, 2);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
    cr_assert_eq(list->end->data, NULL);
}

Test(list_insert_end, null)
{
    list_t *list = NULL;
    node_t *node = NULL;

    node = node_create(NULL, NULL, NULL);
    list = list_insert_end(list, node);
    cr_assert_eq(list, NULL);
}

Test(list_insert_end, empty)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    node = node_create("ok", NULL, NULL);
    list = list_insert_end(list, node);
    cr_assert_eq(list->len, 1);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
}

Test(list_insert_end, two)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, "bb", NULL, NULL);
    list = list_append(list, "aa", NULL, NULL);
    cr_assert_neq(list->start, list->end);
    node = node_create("ok", NULL, NULL);
    list = list_insert_end(list, node);
    cr_assert_eq(list->len, 3);
    cr_assert_str_eq(L_DATA(L_LAST(list)), "ok");
    cr_assert_str_eq(list->start->data, "bb");
    cr_assert_str_eq(list->start->next->data, "aa");
}
