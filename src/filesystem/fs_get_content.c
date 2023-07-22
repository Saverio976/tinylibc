/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** get filess content from a buffer
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "tlcfs.h"
#include "tlcstrings.h"

static char *error_malloc(int fd)
{
    close(fd);
    return (NULL);
}

static char *fill_buffer(int fd, char *buffer, size_t size)
{
    ssize_t nbyte = read(fd, buffer, (unsigned long) size);

    if (nbyte != (ssize_t) size || (size_t) nbyte != size) {
        free(buffer);
        close(fd);
        return (NULL);
    }
    buffer[size] = '\0';
    return (buffer);
}

/**
** @brief get the entire content of file path (if readable)
** @param path
** @return null if path is not readable; otherwise the content
**/
char *fs_get_content(char const *path)
{
    char *buffer = NULL;
    size_t size = 0;
    int fd = fs_open_ronly(path);

    if (fd < 0) {
        return (NULL);
    }
    size = fs_get_size(path);
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL) {
        return (error_malloc(fd));
    }
    buffer = fill_buffer(fd, buffer, size);
    return (buffer);
}
