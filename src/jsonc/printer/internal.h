/*
** EPITECH PROJECT, 2023
** (My) Tiny Lib C
** File description:
** internal header for printer json
*/

#ifndef PRINT_JSON_INTERNAL_H__
    #define PRINT_JSON_INTERNAL_H__

    #include "tlcjson.h"

int prety_print_rec(int fd, any_t *any, int indent);

int do_print_dico(int fd, any_t *any, int indent);
int do_print_array(int fd, any_t *any, int indent);
int do_print_string(int fd, any_t *any, int indent);
int do_print_number(int fd, any_t *any, int indent);

#endif
