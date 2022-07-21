/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include "tlcllists.h"

Test(list_delete, null)
{
    list_delete(NULL);
    cr_assert_eq(0, 0);
}

Test(list_delete, empty)
{
    list_t *list = NULL;

    list = list_create();
    list_delete(list);
    cr_assert_eq(0, 0);
}

static void put_one_if_not_null(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
    *((int *) ptr) = 1;
}

Test(list_delete, one)
{
    list_t *list = NULL;
    int val = 0;

    list = list_create();
    list = list_append(list, NULL, put_one_if_not_null, NULL);
    list_delete(list);
    put_one_if_not_null(&val);
    cr_assert_eq(val, 1);
}

static void increment_if_not_null(void *ptr)
{
    static int val = 0;

    if (ptr == NULL) {
        val += 1;
        return;
    }
    *((int *) ptr) = val;
}

Test(list_delete, many)
{
    list_t *list = NULL;
    int val = 0;

    list = list_create();
    for (int i = 0; i < 4; i++) {
        list = list_append(list, NULL, increment_if_not_null, NULL);
    }
    list_delete(list);
    increment_if_not_null(&val);
    cr_assert_eq(val, 4);
}
