/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** add a string to the dico root
*/

#include <stdlib.h>
#include "tlcstrings.h"
#include "tlcjson.h"

static any_t *create_any_string(const char *str)
{
    any_t *any = NULL;
    char *new = NULL;

    any = malloc(sizeof(any_t));
    if (any == NULL) {
        return NULL;
    }
    new = x_strdup(str);
    if (new == NULL) {
        free(any);
        return NULL;
    }
    any->type = STR;
    any->value.str = new;
    return any;
}

any_t *creator_add_string(any_t *root, const char *key, const char *string)
{
    any_t *string_any = NULL;

    if (root == NULL || key == NULL || string == NULL || root->type != DICT) {
        return root;
    }
    string_any = create_any_string(string);
    if (string_any == NULL) {
        return root;
    }
    root->value.dict = dico_add(root->value.dict, key, string_any,
        destroy_any);
    return root;
}
