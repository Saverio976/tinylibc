/*
** EPITECH PROJECT, 2022
** (my) Tiny Lib
** File description:
** utils function and macro
*/

#ifndef TLS_UTILS_H_
    #define TLS_UTILS_H_

/**
** @def UNUSED
** @brief syntax sugar for __attribute__((unused))
**/
    #define UNUSED __attribute__((unused))

    #define _START_RNG(start) int start_tmp = (start) 
    #define _END_RNG(end, step) start_tmp = start_tmp + (step)
    #define _MID_RNG(end) start_tmp < (end)
    #define _RNG(start, end) _START_RNG(start); _MID_RNG(end)
/**
** @def RANGE(start, end, step)
** @brief a for (RANGE(0, 10, 1)) { ... } that iterates from start to end
** @param start the start
** @param end the end
** @param step the step to inc the start each time
**/
    #define RANGE(start, end, step) _RNG(start, end); _END_RNG(end, step)

/**
** @brief free if `ptr` is not null
**
** @param ptr to free
**/
void free_ifnotnull(void *ptr);

/**
** @brief function that do nothing; utils for ternary with one function call
**/
void return_void(void);

/**
** @brief free a 2d array of char
**
** @param arr the 2d array
**/
void free_char_2d(char **arr);

#endif
