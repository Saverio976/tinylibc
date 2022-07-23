/*
** EPITECH PROJECT, 2022
** (my) TinyLibC
** File description:
** print string
*/

#include <stdbool.h>
#include <unistd.h>
#include "tlcstrings.h"
#include "tlcstdios.h"

int x_puts(const char *str, bool newline)
{
    int len = 0;

    if (str == NULL) {
        return (0);
    }
    len = write(1, str, x_strlen(str));
    if (newline == true) {
        len += x_putc('\n', false);
    }
    return (len);
}
