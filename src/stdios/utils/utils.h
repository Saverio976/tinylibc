/*
** EPITECH PROJECT, 2022
** (my) TinyLibC
** File description:
** prototypes of utils function for printf and sprintf
*/

#ifndef TLS_UTILS_H_STDIOS_H_
    #define TLS_UTILS_H_STDIOS_H_

    #include <stddef.h>
    #include <stdarg.h>

char *ptrtohexa(void *ptr, const char *base_16);

char *ptr_specifier(va_list ap, const char *res, size_t *index);

char *i_specifier(va_list ap, const char *rest, size_t *index);

char *x_low_specifier(va_list ap, const char *rest, size_t *index);

char *x_up_specifier(va_list ap, const char *rest, size_t *index);

char *c_specifier(va_list ap, const char *rest, size_t *index);

char *s_specifier(va_list ap, const char *rest, size_t *index);

char *mod_specifier(va_list ap, const char *rest, size_t *index);

#endif
