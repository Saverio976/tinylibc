/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** create an empty any t
*/

#include <stdlib.h>
#include "tlcdico.h"
#include "tlcjson.h"

any_t *create_empty_json(void)
{
    any_t *any = NULL;

    any = malloc(sizeof(any_t));
    if (any == NULL) {
        return NULL;
    }
    any->type = DICT;
    any->value.dict = dico_create();
    return any;
}
