/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** find something in list
*/

#include <stddef.h>
#include <stdbool.h>
#include "tlcllists.h"

node_result_t list_find_ptrdata(list_t *list, void *data)
{
    node_result_t res = {.node_index = -1, .node_ptr = NULL};
    int index = 0;

    if (list == NULL) {
        return (res);
    }
    FOREACH(node, list)
        if (GETDATA(node) == data) {
            res.node_index = index;
            res.node_ptr = node;
            return (res);
        }
        index += 1;
    END
    return (res);
}

int list_find_ptrnode(list_t *list, node_t *node_ptr)
{
    int index = 0;

    if (list == NULL) {
        return (-1);
    }
    FOREACH(node, list)
        if (node == node_ptr) {
            return (index);
        }
        index += 1;
    END
    return (-1);
}

node_result_t list_find_f(list_t *list,
    bool (is_this_result)(void *node_data, void *param), void *param)
{
    node_result_t res = {.node_index = -1, .node_ptr = NULL};
    int index = 0;

    if (list == NULL) {
        return (res);
    }
    FOREACH(node, list)
        if (is_this_result(GETDATA(node), param)) {
            res.node_ptr = node;
            res.node_index = index;
            return (res);
        }
        index += 1;
    END
    return (res);
}
