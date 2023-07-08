/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** add an array to the dico root
*/

#include <stdlib.h>
#include "tlcllists.h"
#include "tlcstrings.h"
#include "tlcjson.h"

static any_t *create_any_array(list_t *lst)
{
    any_t *any = NULL;

    any = malloc(sizeof(any_t));
    if (any == NULL) {
        return NULL;
    }
    any->type = ARRAY;
    any->value.array = lst;
    return any;
}

any_t *creator_add_array(any_t *root, const char *key, list_t *arr)
{
    any_t *arr_any = NULL;

    if (root == NULL || key == NULL || arr == NULL || root->type != DICT) {
        return root;
    }
    arr_any = create_any_array(arr);
    if (arr_any == NULL) {
        return root;
    }
    root->value.dict = dico_add(root->value.dict, key, arr_any, destroy_any);
    return root;
}
