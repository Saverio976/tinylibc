#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>

#include "tlccirc_buf_inf.h"

Test(empty, empty_a_circ_buf_inf)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");
    cr_assert_not_null(buffer);
    cr_assert_eq(circ_buf_inf_is_empty(buffer), true);
}

Test(empty, not_empty)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");
    cr_assert_not_null(buffer);
    cr_assert_eq(circ_buf_inf_is_empty(buffer), true);
    circ_buf_inf_write(buffer, "a");
    cr_assert_eq(circ_buf_inf_is_empty(buffer), false);
}

Test(empty, not_empty_and_to_empty)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    cr_assert_not_null(buffer);
    cr_assert_eq(circ_buf_inf_is_empty(buffer), true);
    circ_buf_inf_write(buffer, "a.");
    cr_assert_eq(circ_buf_inf_is_empty(buffer), false);
    cr_assert_not_null(circ_buf_inf_read(buffer));
    cr_assert_eq(circ_buf_inf_is_empty(buffer), true);
}

Test(is_read_ready, is_read_ready)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    cr_assert_not_null(buffer);
    cr_assert_eq(circ_buf_inf_is_read_ready(buffer), false);
    circ_buf_inf_write(buffer, "a.");
    cr_assert_eq(circ_buf_inf_is_read_ready(buffer), true);
    circ_buf_inf_read(buffer);
    cr_assert_eq(circ_buf_inf_is_read_ready(buffer), false);
}
