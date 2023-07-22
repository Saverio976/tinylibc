/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** malloc n char and fill with 0
*/

#include <stddef.h>
#include <stdlib.h>
#include "tlcstdlibs.h"

char *x_calloc(size_t n)
{
    char *new = NULL;

    new = malloc(sizeof(char) * n);
    if (new == NULL) {
        return (NULL);
    }
    for (size_t i = 0; i < n; i++) {
        new[i] = '\0';
    }
    return (new);
}
