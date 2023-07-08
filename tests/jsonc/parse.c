#include <criterion/criterion.h>

#include "../includes/tlcjson.h"

Test(parse, parse_array)
{
    any_t *json = parse_json_str("{\"array\": [3, 2, 1]}");
    any_t *ind;

    cr_assert_not_null(json);

    ind = get_from_any(json, "da", "array", 0);
    cr_assert_not_null(ind);
    cr_assert_eq(ind->type, INT);
    cr_assert_eq(ind->value.i, 3);

    ind = get_from_any(json, "da", "array", 1);
    cr_assert_not_null(ind);
    cr_assert_eq(ind->type, INT);
    cr_assert_eq(ind->value.i, 2);

    ind = get_from_any(json, "da", "array", 2);
    cr_assert_not_null(ind);
    cr_assert_eq(ind->type, INT);
    cr_assert_eq(ind->value.i, 1);

    ind = get_from_any(json, "da", "array", 3);
    cr_assert_null(ind);
}

Test(parse, file_not_exists)
{
    any_t *json = parse_json_file("not_exists.json");
    cr_assert_null(json);
}

#define NB_FILES 9

static const char json_files[NB_FILES][50] = {
    "./tests/jsonc/sample_json/basic.json",
    "./tests/jsonc/sample_json/basic1.json",
    "./tests/jsonc/sample_json/basic2.json",
    "./tests/jsonc/sample_json/basic3.json",
    "./tests/jsonc/sample_json/basic4.json",
    "./tests/jsonc/sample_json/basic5.json",
    "./tests/jsonc/sample_json/basic6.json",
    "./tests/jsonc/sample_json/basic7.json",
    "./tests/jsonc/sample_json/basic_empty.json",
};

Test(parse, parse_sample)
{
    for (int i = 0; i < NB_FILES; i++) {
        any_t *json = parse_json_file(json_files[i]);
        cr_assert_not_null(json);
    }
}
