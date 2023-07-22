/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** remove some char at start and end
*/

#include <stddef.h>
#include <stdlib.h>
#include "tlcstrings.h"

char *x_strstrip(const char *s, const char *chars)
{
    size_t start = 0;
    size_t end = 0;
    char *new = NULL;

    if (s == NULL || chars == NULL) {
        return (NULL);
    }
    for (; s[start] != '\0' && x_strchr(chars, s[start]) != NULL; start++);
    end = x_strlen(s) - 1;
    for (; end >= start && x_strchr(chars, s[end]) != NULL; end--);
    new = malloc(sizeof(char) * ((end - start) + 1));
    if (new == NULL) {
        return (NULL);
    }
    new[end - start] = '\0';
    new = x_strncpy(new, s + start, (unsigned long) (end - start) + 1);
    return (new);
}
