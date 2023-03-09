#include "tlcllists.h"
#include "tlcstrings.h"
#include "tlcutils.h"
#include "tlcstdios.h"

int main(int ac, const char *av[])
{
    list_t *list = list_create();

    x_puts("Hewwo fwiends!!", true);
    for (int i = 0; i < ac; i++) {
        list = list_append(list, x_strdup(av[i]), &free_ifnotnull, NULL);
    }
    // Now, you have a list of av
    for (L_EACH(x, list)) { // for each node named x in the list list
        // do something with x
        // more function and macro to
        // https://saverio976.github.io/tinylibc/d8/d07/tlcllists_8h.html
        x_printf("av[%d] = %s\n", list_find_ptrnode(list, x), L_DATA(x));
    }
    return (0);
}
