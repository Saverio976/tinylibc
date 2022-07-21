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

Test(list_duplicate, null)
{
    list_t *list = NULL;
    list_t *new = NULL;

    new = list_duplicate(list);
    cr_assert_eq(new, NULL);
}

Test(list_duplicate, empty)
{
    list_t *list = NULL;
    list_t *new = NULL;

    list = list_create();
    new = list_duplicate(list);
    cr_assert_neq(new, NULL);
    cr_assert_eq(new->start, NULL);
    cr_assert_eq(new->len, 0);
    cr_assert_eq(new->end, 0);
}

static void *x_strdup_void(void *ptr)
{
    return (x_strdup(ptr));
}

Test(list_duplicate, elemnt_not_copy_mixed)
{
    list_t *list = NULL;
    list_t *new = NULL;
    char *ok[] = {"ok", "bh"};

    list = list_create();
    list = list_append(list, ok[0], NULL, x_strdup_void);
    list = list_append(list, "ra", NULL, NULL);
    list = list_append(list, ok[1], NULL, x_strdup_void);
    list = list_append(list, "ta", NULL, NULL);
    new = list_duplicate(list);
    cr_assert_str_eq(GETDATA(FIRST(new)), ok[0]);
    cr_assert_str_eq(GETDATA(NEXT(FIRST(new))), ok[1]);
    cr_assert_eq(LEN(new), 2);
}
