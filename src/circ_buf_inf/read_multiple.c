/*
** EPITECH PROJECT, 2023
** Zappy Server
** File description:
** circular buffer lib read multiple
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "tlcstrings.h"
#include "tlccirc_buf_inf.h"
#include "tlcutils.h"

static char *concat(char *a, char *b)
{
    char *new = NULL;
    size_t size = 0;

    size += (a == NULL) ? 0 : x_strlen(a);
    size += (b == NULL) ? 0 : x_strlen(b);
    new = calloc(size + 1, sizeof(char));
    if (new == NULL) {
        return NULL;
    }
    if (a != NULL) {
        strcat(new, a);
    }
    if (b != NULL) {
        strcat(new, b);
    }
    return new;
}

char *circ_buf_inf_read_multiple(circ_buf_inf_t *buffer)
{
    char *new = NULL;
    char *tmp = NULL;
    char *new_tmp = NULL;

    if (buffer == NULL) {
        return NULL;
    }
    while (circ_buf_inf_is_read_ready(buffer) == true) {
        tmp = circ_buf_inf_read(buffer);
        new_tmp = concat(new, tmp);
        if (new_tmp == NULL) {
            free_ifnotnull(tmp);
            break;
        }
        free(new);
        new = new_tmp;
    }
    return new;
}
