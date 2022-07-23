#include "tlcllists.h"
#include "tlcstrings.h"
#include "tlcutils.h"

void *copy_str(void *ptr)
{
    return (x_strdup(ptr));
}

int main(int ac, const char *av[])
{
    list_t *list = list_create();

    for (int i = 0; i < ac; i++) {
        list = list_append(list, x_strdup(av[i]), &free_ifnotnull, &copy_str);
    }
    // Now, you have a list of av
    FOREACH(x, list) // for each node named x in the list list
        // do something with x
        // more function and macro to
        // https://saverio976.github.io/tinylibc/d8/d07/tlcllists_8h.html
    END
    return (0);
}
