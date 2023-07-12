/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** check if s starts with needle
*/

#include "tlcstrings.h"

int x_strstartswith(const char *str, const char *needle)
{
    if (x_strlen(needle) > x_strlen(str)) {
        return (0);
    }
    for (int i = 0; needle[i] != '\0'; i++) {
        if (str[i] != needle[i]) {
            return (0);
        }
    }
    return (1);
}
