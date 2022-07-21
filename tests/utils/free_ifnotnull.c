/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "tlcutils.h"

Test(free_ifnotnull, null)
{
    free_ifnotnull(NULL);
}

Test(free_ifnotnull, not_null)
{
    free_ifnotnull(malloc(12));
}
