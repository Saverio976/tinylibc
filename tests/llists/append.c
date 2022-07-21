/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcstrings.h"
#include "tlcllists.h"
#include "tlcutils.h"

Test(list_append, null_list)
{
    list_t *list = NULL;

    list = list_append(list, "ok", NULL, NULL);
    cr_assert_eq(list, NULL);
}

Test(list_append, ok)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, "ok", NULL, NULL);
    cr_assert_neq(list, NULL);
    node = FIRST(list);
    cr_assert_str_eq(GETDATA(node), "ok");
    cr_assert_eq(NEXT(node), NULL);
    cr_assert_eq(node->copy, NULL);
    cr_assert_eq(node->destroy, NULL);
}

Test(list_append, ptr_malloc_to_free)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, x_strdup("ok"), free_ifnotnull, NULL);
    cr_assert_neq(list, NULL);
    node = FIRST(list);
    cr_assert_str_eq(GETDATA(node), "ok");
    cr_assert_eq(NEXT(node), NULL);
    cr_assert_eq(node->copy, NULL);
    cr_assert_eq(node->destroy, free_ifnotnull);
}

static void *x_strdup_void(void *ptr)
{
    return (x_strdup(ptr));
}

Test(list_append, ptr_malloc_to_free_with_copy)
{
    list_t *list = NULL;
    node_t *node = NULL;

    list = list_create();
    list = list_append(list, x_strdup("ok"), free_ifnotnull, x_strdup_void);
    cr_assert_neq(list, NULL);
    node = FIRST(list);
    cr_assert_str_eq(GETDATA(node), "ok");
    cr_assert_eq(NEXT(node), NULL);
    cr_assert_eq(node->copy, x_strdup_void);
    cr_assert_eq(node->destroy, free_ifnotnull);
}

Test(list_append, many)
{
    list_t *list = NULL;
    node_t *node = NULL;
    char *tab[] = {"ok", "salut", "", NULL};

    list = list_create();
    cr_assert_neq(list, NULL);
    for (int i = 0; tab[i] != NULL; i++) {
        list = list_append(list, x_strdup(tab[i]), free_ifnotnull, NULL);
    }
    node = FIRST(list);
    for (int i = 0; tab[i] != NULL; i++) {
        cr_assert_neq(node, NULL);
        cr_assert_str_eq(GETDATA(node), tab[i]);
        cr_assert_eq(node->copy, NULL);
        cr_assert_eq(node->destroy, free_ifnotnull);
        node = NEXT(node);
    }
    cr_assert_eq(node, NULL);
}
