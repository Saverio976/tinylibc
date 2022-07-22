# (my) TinyLibC

**just some basic functions (and why not, some non basic)**

## DOC

use doxygen:
- doc available at [doc](https://saverio976.github.io/tinylibc/)
- each function have doc with the (auto)completion of your IDE

## Example

- using **list**
```c
#include "tlcllists.h"
#include "tlcstrings.h"
#include "tlcutils.h"

void *copy_str(void *ptr)
{
    return (x_strdup(ptr));
}

int main(int ac, cosnt char *av[])
{
    list_t *list = list_create();

    for (int i = 0; i < ac; i++) {
        list = list_append(list, x_strdup(av[i]), &free_ifnotnull, &copy_str);
    }
    // Now, you have a list of av
    FOREACH(x, list) // for each node named x in the list list
        // do something with x
        // more function and macro to https://saverio976.github.io/tinylibc/d8/d07/tlcllists_8h.html
    END
}
```

## Build

```bash
make
```
this will output the file  `libtinylibc.a`

*object are compiled to `obj` folder (and makefile dont relink !!!) (i'm proud of that xD)*

## Use it

compile your c code (change value of CC to your c compiler and PATHTINYLIBC to the right value):
```bash
export CC=gcc
export PATHTINYLIBC=path/where/libtinylibc.a/is/
$CC -L $PATHTINYLIBC -ltinylibc -I $PATHTINYLIBC/includes
```
