/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include "tlcllists.h"

Test(list_index, null)
{
    list_t *list = NULL;
    node_t *node = 0;

    node = list_index(list, 1);
    cr_assert_eq(node, NULL);
}

Test(list_index, first_of_one)
{
    list_t *list = NULL;
    node_t *node = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    node = list_index(list, 0);
    cr_assert_eq(node, FIRST(list));
}

Test(list_index, first_of_two)
{
    list_t *list = NULL;
    node_t *node = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    list = list_append(list, NULL, NULL, NULL);
    node = list_index(list, 0);
    cr_assert_eq(node, FIRST(list));
}

Test(list_index, second_of_two)
{
    list_t *list = NULL;
    node_t *node = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    list = list_append(list, NULL, NULL, NULL);
    node = list_index(list, 1);
    cr_assert_eq(node, NEXT(FIRST(list)));
}


Test(list_index, first_of_two_neg)
{
    list_t *list = NULL;
    node_t *node = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    list = list_append(list, NULL, NULL, NULL);
    node = list_index(list, -1);
    cr_assert_eq(node, FIRST(list));
}

Test(list_index, second_of_two_overflow)
{
    list_t *list = NULL;
    node_t *node = 0;

    list = list_create();
    list = list_append(list, NULL, NULL, NULL);
    list = list_append(list, NULL, NULL, NULL);
    node = list_index(list, 4);
    cr_assert_eq(node, NEXT(FIRST(list)));
}
