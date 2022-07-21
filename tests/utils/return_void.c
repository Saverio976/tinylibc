/*
** EPITECH PROJECT, 2022
** test criterion
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include "tlcutils.h"

Test(return_void, nothing)
{
    return_void();
    cr_assert_eq(0, 0);
}
