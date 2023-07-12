#include <criterion/criterion.h>

#include "../includes/tlcstrings.h"

Test(x_strstartswith, basic)
{
    cr_assert_eq(x_strstartswith("abc", "abc"), 1);
}

Test(x_strstartswith, basic2)
{
    cr_assert_eq(x_strstartswith("abcd", "abc"), 1);
}

Test(x_strstartswith, basic3)
{
    cr_assert_eq(x_strstartswith("abcdef", "abcf"), 0);
}

Test(x_strstartswith, basic4)
{
    cr_assert_eq(x_strstartswith("a", "abcf"), 0);
}
