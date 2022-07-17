/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** delete the list
*/

#include <stddef.h>
#include <stdlib.h>
#include "tlcllists.h"

void list_delete(list_t *list)
{
    node_t *curr = NULL;

    if (list == NULL) {
        return;
    }
    curr = FIRST(list);
    for (node_t *tmp = NULL; curr != NULL; curr = tmp) {
        tmp = NEXT(curr);
        DESTROY(curr);
        free(curr);
    }
    free(list);
}
