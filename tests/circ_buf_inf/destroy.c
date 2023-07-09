#include <criterion/criterion.h>
#include <criterion/internal/test.h>

#include "tlccirc_buf_inf.h"

Test(destroy, destroys_null)
{
    circ_buf_inf_destroy(NULL);
}

Test(destroy, destroys_a_circ_buf_inf)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");
    cr_assert_not_null(buffer);
    circ_buf_inf_destroy(buffer);
}
