/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "tlcllists.h"

Test(list_create, only_create)
{
    list_t *list = NULL;

    list = list_create();
    cr_assert_neq(list, NULL);
}

Test(list_create, with_destroy)
{
    list_t *list = NULL;

    list = list_create();
    cr_assert_neq(list, NULL);
    list_delete(list);
}
