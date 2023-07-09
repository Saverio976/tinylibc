/*
** EPITECH PROJECT, 2023
** MyTeams
** File description:
** circular buffer lib create
*/

#include <stdlib.h>
#include <string.h>
#include "tlccirc_buf_inf.h"
#include "tlcllists.h"

circ_buf_inf_t *circ_buf_inf_create(const char *end_pattern)
{
    circ_buf_inf_t *buffer = NULL;

    if (end_pattern == NULL) {
        return (NULL);
    }
    buffer = malloc(sizeof(circ_buf_inf_t));
    if (buffer == NULL) {
        return (NULL);
    }
    memset(buffer, 0, sizeof(circ_buf_inf_t));
    buffer->buffer = list_create();
    if (buffer->buffer == NULL) {
        circ_buf_inf_destroy(buffer);
        return NULL;
    }
    buffer->end_pattern = end_pattern;
    return (buffer);
}
