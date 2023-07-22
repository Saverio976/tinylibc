/*
** EPITECH PROJECT, 2023
** (My) Tiny Lib C
** File description:
** internal header for parser
*/

#ifndef PARSER_INTERNAL_H
    #define PARSER_INTERNAL_H

    #include "tlcjson.h"

any_t *parse_dico(const char *str, int *global_index);
any_t *parse_array(const char *str, int *global_index);
any_t *parse_string(const char *str, int *global_index);
any_t *parse_number(const char *str, int *global_index);
any_t *parse_unknow(const char *str, int *global_index);
bool is_tokken(const char *str, char tokken, int global_index, char escape);
bool parse_dico_is_empty(const char **str, int *global_index);
bool parse_array_is_empty(const char **str, int *global_index);

#endif
