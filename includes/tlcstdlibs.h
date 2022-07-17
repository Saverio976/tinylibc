/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** prototypes of stdlibs part
*/

#ifndef TLS_STDLIBS_H_
    #define TLS_STDLIBS_H_

/**
** @brief malloc n char and fill with 0
**
** @param n number to alloc
**
** @return ptr to the first n allocated
**/
char *x_calloc(int n);

/**
** @brief malloc n char * and fill with 0
**
** @param n number to alloc
**
** @return ptr to the first n allocated
**/
char **x_ccalloc(int n);

#endif
