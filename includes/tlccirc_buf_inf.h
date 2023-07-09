/*
** EPITECH PROJECT, 2023
** MyTeams
** File description:
** circular buffer lib
*/

#ifndef CIRCULAR_BUFFER_INF_H_
    #define CIRCULAR_BUFFER_INF_H_

    #include <stddef.h>
    #include <stdbool.h>
    #include "tlcllists.h"

struct circ_buf_inf_s {
    list_t *buffer;
    const char *end_pattern;
};
typedef struct circ_buf_inf_s circ_buf_inf_t;

/**
** @brief create a circular buffer
**
** @param end_pattern the pattern of the end that says we can write to another
**
** @return a circular buffer
**/
circ_buf_inf_t *
circ_buf_inf_create(const char *end_pattern);

/**
** @brief destroy a circular buffer
**
** @param buffer the circular buffer
**/
void circ_buf_inf_destroy(circ_buf_inf_t *buffer);

/**
** @brief add a char* to the circular buffer
**
** @param buffer the circular buffer
** @param str the char* to add (it will be strdup'ed)
**/
void circ_buf_inf_write(circ_buf_inf_t *buffer, const char *str);

/**
** @brief read a char* from the circular buffer
**
** @param buffer the circular buffer
**
** @return a char* (malloc'ed); NULL if empty or not `end_pattern`'ed
**/
char *circ_buf_inf_read(circ_buf_inf_t *buffer);

/**
** @brief read a char* from the circular buffer until last `end_pattern`
**
** @param buffer the circular buffer
**
** @return a char* (malloc'ed); NULL if empty or not `end_pattern`'ed
**/
char *circ_buf_inf_read_multiple(circ_buf_inf_t *buffer);

/**
** @brief check if circular buffer is empty
**
** @param buffer the circular buffer
**
** @return true if empty; false otherwise
**/
bool circ_buf_inf_is_empty(circ_buf_inf_t *buffer);

/**
** @brief check if circular buffer is ready to read (=> `end_pattern`'ed)
**
** @param buffer the circular buffer
**
** @return true if ready; false otherwise
**/
bool circ_buf_inf_is_read_ready(circ_buf_inf_t *buffer);

#endif
