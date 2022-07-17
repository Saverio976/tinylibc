/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** get node at index
*/

#include <stddef.h>
#include "tlcllists.h"

static node_t *list_index_search(list_t *list, int index)
{
    int curr = 0;

    FOREACH(node, list)
        if (index == curr) {
            return (node);
        }
    curr += 1;
    END
    return (NULL);
}

node_t *list_index(list_t *list, int index)
{
    if (list == NULL) {
        return (NULL);
    }
    if (index >= list->len) {
        return (LAST(list));
    } else if (index <= 0) {
        return (FIRST(list));
    } else {
        return (list_index_search(list, index));
    }
}
