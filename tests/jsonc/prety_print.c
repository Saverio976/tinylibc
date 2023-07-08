#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../includes/tlcjson.h"

Test(prety_print, prety_print, .init = cr_redirect_stdout)
{
    const char str[] = "{\"array\": [3, 2, 1], \"string\": \"test\"}";
    const char expect[] = "{\n    \"array\": [3, 2, 1],\n    \"string\": \"test\"\n}\n";
    any_t *json = parse_json_str(str);

    cr_assert_not_null(json);
    prety_print(json, 1);
    cr_assert_stdout_eq_str(expect);
}
