/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcllists.h"

Test(list_remove_ptrnode, null)
{
    list_t *list = NULL;
    int val = 0;

    val = list_remove_ptrnode(list, (void *) 1);
    cr_assert_eq(val, 0);
}

Test(list_remove_ptrnode, ok_first)
{
    list_t *list = NULL;
    int val = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    val = list_remove_ptrnode(list, L_FIRST(list));
    cr_assert_eq(val, 1);
    cr_assert_eq(list->len, 0);
}

Test(list_remove_ptrnode, ok_end)
{
    list_t *list = NULL;
    int val = 0;

    list = list_create();
    list = list_append(list, "ok", NULL, NULL);
    list = list_append(list, NULL, NULL, NULL);
    val = list_remove_ptrnode(list, L_LAST(list));
    cr_assert_eq(val, 1);
    cr_assert_eq(list->len, 1);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
}

Test(list_remove_ptrnode, ok_mid)
{
    list_t *list = NULL;
    int val = 0;

    list = list_create();
    list = list_append(list, "ok", NULL, NULL);
    list = list_append(list, "mid", NULL, NULL);
    list = list_append(list, "end", NULL, NULL);
    val = list_remove_ptrnode(list, L_NEXT(L_FIRST(list)));
    cr_assert_eq(val, 1);
    cr_assert_eq(list->len, 2);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
    cr_assert_str_eq(L_DATA(L_LAST(list)), "end");
    cr_assert_str_eq(L_DATA(L_NEXT(L_FIRST(list))), "end");
}

Test(list_remove_ptrdata, null)
{
    list_t *list = NULL;
    int val = 0;

    val = list_remove_ptrdata(list, (void *) 1);
    cr_assert_eq(val, 0);
}

Test(list_remove_ptrdata, ok_first)
{
    list_t *list = NULL;
    int val = 0;
    char tab[] = "ok";

    list = list_create();
    list = list_append(list, tab, NULL, NULL);
    val = list_remove_ptrdata(list, tab);
    cr_assert_eq(val, 1);
    cr_assert_eq(list->len, 0);
}

Test(list_remove_ptrdata, ok_end)
{
    list_t *list = NULL;
    int val = 0;
    char tab[] = "end";

    list = list_create();
    list = list_append(list, "ok", NULL, NULL);
    list = list_append(list, tab, NULL, NULL);
    val = list_remove_ptrdata(list, tab);
    cr_assert_eq(val, 1);
    cr_assert_eq(list->len, 1);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
}

Test(list_remove_ptrdata, ok_mid)
{
    list_t *list = NULL;
    int val = 0;
    char tab[] = "mid";

    list = list_create();
    list = list_append(list, "ok", NULL, NULL);
    list = list_append(list, tab, NULL, NULL);
    list = list_append(list, "end", NULL, NULL);
    val = list_remove_ptrdata(list, tab);
    cr_assert_eq(val, 1);
    cr_assert_eq(list->len, 2);
    cr_assert_str_eq(L_DATA(L_FIRST(list)), "ok");
    cr_assert_str_eq(L_DATA(L_LAST(list)), "end");
    cr_assert_str_eq(L_DATA(L_NEXT(L_FIRST(list))), "end");
}
