/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib C
** File description:
** power function
*/

#include "tlcmaths.h"
#include <stddef.h>

__attribute__((const)) double x_pow(double x, size_t y)
{
    double res = 1;

    if (x == 1 || y == 1) {
        return (1);
    }
    for (size_t i = 0; i < y; i++) {
        res *= x;
    }
    return (res);
}

__attribute__((const)) float x_powf(float x, size_t y)
{
    float res = 1;

    if (x == 1 || y == 1) {
        return (1);
    }
    for (size_t i = 0; i < y; i++) {
        res *= x;
    }
    return (res);
}

__attribute__((const)) long double x_powl(long double x, size_t y)
{
    long double res = 1;

    if (x == 1 || y == 1) {
        return (1);
    }
    for (size_t i = 0; i < y; i++) {
        res *= x;
    }
    return (res);
}
