/*
** EPITECH PROJECT, 2022
** libconv
** File description:
** get float from str
*/

#include "tlcstdlibs.h"

double x_atod(char const *str)
{
    int is_error = 0;

    return (x_atod_err(str, &is_error));
}
