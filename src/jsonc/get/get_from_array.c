/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get from array
*/

#include <stddef.h>
#include <stdlib.h>
#include "tlcllists.h"
#include "tlcstrings.h"
#include "tlcjson.h"

static char **fill_ret(char **ret, list_t *array)
{
    any_t *any = NULL;
    int i = 0;

    for (L_EACH(node, array)) {
        any = L_DATA(node);
        if (any == NULL || any->type != STR) {
            return NULL;
        }
        ret[i++] = x_strdup(any->value.str);
        ret[i] = NULL;
    }
    return ret;
}

float *get_any_float_array(any_t *array)
{
    float *ret = NULL;
    any_t *any = NULL;
    int i = 0;

    if (array == NULL || array->type != ARRAY) {
        return NULL;
    }
    ret = malloc(sizeof(float) * ((unsigned long) array->value.array->len));
    if (ret == NULL) {
        return NULL;
    }
    for (L_EACH(node, array->value.array)) {
        any = L_DATA(node);
        if (any == NULL || any->type != FLOAT) {
            free(ret);
            return NULL;
        }
        ret[i++] = any->value.f;
    }
    return ret;
}

char **get_any_string_array(any_t *array)
{
    char **ret = NULL;

    if (array == NULL || array->type != ARRAY) {
        return NULL;
    }
    ret = malloc(sizeof(char *) *
        ((size_t) array->value.array->len + 1));
    if (ret == NULL) {
        return NULL;
    }
    ret[array->value.array->len] = NULL;
    if (fill_ret(ret, array->value.array) == NULL) {
        for (size_t i = 0; ret[i] != NULL; i++) {
            free(ret[i]); 
        }
        free(ret);
        return NULL;
    }
    return ret;
}

int *get_any_int_array(any_t *array)
{
    int *ret = NULL;
    any_t *any = NULL;
    int i = 0;

    if (array == NULL || array->type != ARRAY) {
        return NULL;
    }
    ret = malloc(sizeof(int) * ((unsigned long) array->value.array->len));
    if (ret == NULL) {
        return NULL;
    }
    for (L_EACH(node, array->value.array)) {
        any = L_DATA(node);
        if (any == NULL || any->type != INT) {
            free(ret);
            return NULL;
        }
        ret[i++] = any->value.i;
    }
    return ret;
}
