#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>

#include "tlccirc_buf_inf.h"

Test(read, reads_from_empty_circ_buf_inf)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    cr_assert_eq(circ_buf_inf_read(buffer), NULL);
}

Test(read, reads_from_ok_buffer)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");
    char *abc;

    circ_buf_inf_write(buffer, "a.");
    abc = circ_buf_inf_read(buffer);
    cr_assert_str_eq(abc, "a.");
}

Test(read, reads_from_not_empty_buffer_but_not_ok)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    circ_buf_inf_write(buffer, "a");
    cr_assert_eq(circ_buf_inf_read(buffer), NULL);
}

Test(read_multiple, basic_1)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    circ_buf_inf_write(buffer, "a.b.");
    cr_assert_str_eq(circ_buf_inf_read_multiple(buffer), "a.b.");
    cr_assert_eq(circ_buf_inf_read(buffer), NULL);
}

Test(read_multiple, basic_2)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    circ_buf_inf_write(buffer, "a");
    circ_buf_inf_write(buffer, "b");
    circ_buf_inf_write(buffer, "c");
    circ_buf_inf_write(buffer, "d.");
    circ_buf_inf_write(buffer, "e.");
    cr_assert_str_eq(circ_buf_inf_read_multiple(buffer), "abcd.e.");
    cr_assert_eq(circ_buf_inf_read(buffer), NULL);
}

Test(read_multiple, basic_3)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");

    circ_buf_inf_write(buffer, "a");
    circ_buf_inf_write(buffer, "bbdede");
    circ_buf_inf_write(buffer, "c");
    circ_buf_inf_write(buffer, "dede.");
    circ_buf_inf_write(buffer, "edezf");
    circ_buf_inf_write(buffer, ".");
    cr_assert_str_eq(circ_buf_inf_read_multiple(buffer), "abbdedecdede.edezf.");
    cr_assert_eq(circ_buf_inf_read(buffer), NULL);
}
