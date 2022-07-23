/*
** EPITECH PROJECT, 2022
** (my) TinyLibC
** File description:
** put a char
*/

#include <stdbool.h>
#include <unistd.h>

int x_putc(char c, bool newline)
{
    int len = 0;
    char nl = '\n';

    len = write(1, &c, 1);
    if (newline == true) {
        len += write(1, &nl, 1);
    }
    return (len);
}
