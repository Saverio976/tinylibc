/*
** EPITECH PROJECT, 2022
** libconv
** File description:
** change string to float (double)
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "tlcstrings.h"
#include "tlcstdlibs.h"
#include "tlcmaths.h"

static size_t get_float_gap(const char *str)
{
    size_t len = 0;
    int i = 0;

    for (; str[i] != '.' && str[i] != '\0'; i++);
    if (str[i] == '\0') {
        return 0;
    }
    i++;
    for (; str[i] != '\0'; i++, len++);
    return len;
}

static int increment_str(int c, char *result, int *indx)
{
    if (c != '.') {
        result[*indx] = (char) c;
        (*indx) += 1;
        result[*indx] = '\0';
    }
    return 0;
}

static char *get_int_str(const char *str)
{
    char *result = NULL;
    int check = 0;
    int indx = 0;

    if (str == NULL) {
        return NULL;
    }
    for (; str[check] != '\0' && str[check] != '.'; check++);
    if (str[check] != '.') {
        return x_strdup(str);
    }
    result = malloc(sizeof(char) * x_strlen(str));
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        increment_str(str[i], result, &indx);
    }
    return result;
}

float x_atof(const char *str)
{
    char *int_str = NULL;
    size_t gap_float = 0;
    int int_nbr = 0;
    double res = 0.0;

    if (str == NULL) {
        return 0;
    }
    int_str = get_int_str(str);
    if (int_str == NULL) {
        return 0;
    }
    int_nbr = x_atoi(int_str);
    gap_float = get_float_gap(str);
    res = ((double) int_nbr) / (x_pow((double) 10, gap_float));
    free(int_str);
    return (float) res;
}
