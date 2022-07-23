/*
** EPITECH PROJECT, 2022
** (my) TinyLibC
** File description:
** string (in custom base) to int
*/

#include <stddef.h>
#include <stdbool.h>
#include "tlcstrings.h"

static const char end_char[] = "\n \v\f\t";

int atoi_base(const char *nb, const char *base)
{
    int result = 0;
    bool is_neg = false;
    char *index = NULL;

    if (nb == NULL) {
        return (0);
    }
    is_neg = (nb[0] == '-') ? true : false;
    for (int i = 0; nb[i] != '\0' && x_strchr(end_char, nb[i]) == NULL; i++) {
        result *= 10;
        index = x_strchr(base, nb[i]);
        if (index == NULL) {
            return (0);
        }
        result -= (int) (index - base);
    }
    result = (is_neg == true) ? result : result * -1;
    return (result);
}
