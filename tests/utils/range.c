#include <criterion/criterion.h>

#include "../includes/tlcutils.h"

Test(range, dix_1)
{
    int val = 0;

    for (RANGE(0, 10, 1)) {
        val++;
    }
    printf("%d\n", val);
    cr_assert_eq(val, 10);
}
