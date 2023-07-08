/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** add an any_t to the dico root
*/

#include <stddef.h>
#include "tlcjson.h"

any_t *creator_add_any(any_t *root, const char *key, any_t *any)
{
    if (root == NULL || key == NULL || any == NULL || root->type != DICT) {
        return root;
    }
    root->value.dict = dico_add(root->value.dict, key, any, destroy_any);
    return root;
}
