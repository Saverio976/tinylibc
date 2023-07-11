#include <criterion/criterion.h>
#include <stdlib.h>

#include "../includes/tlcutils.h"

Test(free_char_2d, null_arr)
{
    char **list = NULL;
    free_char_2d(list);
}

Test(free_char_2d, null_arr2)
{
    char **list = malloc(sizeof(char *) * 2);
    list[1] = NULL;
    list[0] = malloc(sizeof(char) * 1);
    free_char_2d(list);
}
