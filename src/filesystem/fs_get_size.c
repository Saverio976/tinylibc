/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** return the nbyte of a file
*/

#include <stddef.h>
#include <unistd.h>
#include "tlcfs.h"

/**
** @brief get size of the content of filepath (if stat can)
** @param path
** @return -1 if stat cant get size; the size else
**/
size_t fs_get_size(char const *path)
{
    int fd = 0;
    size_t ret = 0;
    ssize_t buf_ret = 0;
    char buffer[512];

    fd = fs_open_ronly(path);
    if (fd <= 0) {
        return ((size_t) -1);
    }
    buf_ret = read(fd, buffer, (unsigned long) 512);
    while (buf_ret > 0) {
        ret += (size_t) buf_ret;
        buf_ret = read(fd, buffer, (unsigned long) 512);
    }
    close(fd);
    return (ret);
}
