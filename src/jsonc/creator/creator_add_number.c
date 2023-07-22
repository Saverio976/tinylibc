/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** add a number to the dico root
*/

#include <stdlib.h>
#include "tlcjson.h"

static any_t *create_any_number(double f)
{
    any_t *any = NULL;

    any = malloc(sizeof(any_t));
    if (any == NULL) {
        return NULL;
    }
    if (f == ((int) f)) {
        any->type = INT;
        any->value.i = (int) f;
    } else {
        any->type = FLOAT;
        any->value.f = (float) f;
    }
    return any;
}

any_t *creator_add_int(any_t *root, const char *key, int number)
{
    any_t *number_any = NULL;

    if (root == NULL || key == NULL || root->type != DICT) {
        return root;
    }
    number_any = create_any_number((double) number);
    if (number_any == NULL) {
        return root;
    }
    root->value.dict = dico_add(root->value.dict, key, number_any, destroy_any);
    return root;
}

any_t *creator_add_float(any_t *root, const char *key, float number)
{
    any_t *number_any = NULL;

    if (root == NULL || key == NULL || root->type != DICT) {
        return root;
    }
    number_any = create_any_number(number);
    if (number_any == NULL) {
        return root;
    }
    root->value.dict = dico_add(root->value.dict, key, number_any, destroy_any);
    return root;
}
