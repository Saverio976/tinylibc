#include <criterion/criterion.h>
#include <criterion/internal/test.h>

#include "tlccirc_buf_inf.h"

Test(create, creates_a_circ_buf_inf)
{
    cr_assert_not_null(circ_buf_inf_create("."));
}

Test(create, creates_a_circ_buf_inf_with_null_end)
{
    cr_assert_null(circ_buf_inf_create(NULL));
}
