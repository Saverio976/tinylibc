#include <criterion/criterion.h>

#include <stdio.h>
#include "../includes/tlcjson.h"
#include "../includes/tlcfs.h"

Test(writer, write_json)
{
    const char path[] = "./test.json";
    remove(path);
    any_t *json = parse_json_str("{\"array\": [3, 2, 1]}");
    int status = write_json(json, path);

    cr_assert_eq(status, JS_OK);
    char *content = fs_get_content(path);
    cr_assert_not_null(content);
    cr_assert_str_eq(content, "{\n    \"array\": [3, 2, 1]\n}\n");
    free(content);
    cr_assert_eq(remove(path), 0);
}
