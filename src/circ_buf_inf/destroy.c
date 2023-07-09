/*
** EPITECH PROJECT, 2023
** MyTeams
** File description:
** circular buffer lib destroy
*/

#include <stdlib.h>
#include "tlccirc_buf_inf.h"
#include "tlcllists.h"

void circ_buf_inf_destroy(circ_buf_inf_t *buffer)
{
    if (buffer == NULL) {
        return;
    }
    if (buffer->buffer != NULL) {
        list_delete(buffer->buffer);
    }
    free(buffer);
}
