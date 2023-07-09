#include <criterion/criterion.h>

#include "tlccirc_buf_inf.h"

Test(write, writes_to_empty_circ_buf_inf)
{
    circ_buf_inf_t *buffer = circ_buf_inf_create(".");
    char *abc;

    circ_buf_inf_write(buffer, "a.");
    circ_buf_inf_write(buffer, "b.");
    abc = circ_buf_inf_read(buffer);
    cr_assert_str_eq(abc, "a.");
    abc = circ_buf_inf_read(buffer);
    cr_assert_str_eq(abc, "b.");
    cr_assert_eq(circ_buf_inf_read(buffer), NULL);
}
