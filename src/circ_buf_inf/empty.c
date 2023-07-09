/*
** EPITECH PROJECT, 2023
** MyTeams
** File description:
** check if buffer is empty
*/

#include <stdbool.h>
#include "tlcllists.h"
#include "tlcstrings.h"
#include "tlccirc_buf_inf.h"

bool circ_buf_inf_is_empty(circ_buf_inf_t *buffer)
{
    if (buffer == NULL) {
        return true;
    }
    if (buffer->buffer->len == 0) {
        return true;
    }
    return false;
}

bool circ_buf_inf_is_read_ready(circ_buf_inf_t *buffer)
{
    if (buffer == NULL || circ_buf_inf_is_empty(buffer) == true) {
        return false;
    }
    if (x_strstr(L_DATA(buffer->buffer->start),
            buffer->end_pattern) != NULL) {
        return true;
    }
    return false;
}
