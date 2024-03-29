/*
** EPITECH PROJECT, 2023
** (my) Tiny Lib C
** File description:
** json header
*/

#ifndef TLS_JSONC_H_
    #define TLS_JSONC_H_

    #include "tlcllists.h"
    #include "tlcdico.h"

enum json_status_err_e {
    JS_OK = 0,
    JS_ERR_PATH = 1,
    JS_ERR_MALLOC = 2,
    JS_ERR_INPUT = 3
};

enum any_type_e {
    STR = 0,
    INT = 1,
    FLOAT = 2,
    ARRAY = 3,
    DICT = 4
};
typedef enum any_type_e any_type_t;

struct any_s {
    any_type_t type;
    union value_s {
        char *str;
        int i;
        float f;
        list_t *array;
        dico_t *dict;
        char c;
    } value;
};
typedef struct any_s any_t;

struct json_s {
    any_t *dico;
    int nb_keys;
};
typedef struct json_s json_t;

// ----------------------------------------------------------------------------

/**
** @brief parse a json file to any_t
**
** @param path path to the json file
**
** @return {
** NULL : path is NULL,
** NULL : path is bad,
** NULL : malloc failed,
** any_t *: the file has been parsed
** }
**/
any_t *parse_json_file(char const path[]);

/**
** @brief parse a char * to any_t
**
** @param str char * to parse
**
** @return {
** NULL : str is NULL,
** NULL : malloc failed,
** any_t *: the char * has been parsed
** }
**/
any_t *parse_json_str(char const *str);

/**
** @brief print any_t to the file descriptor
**
** @param any the any_t to print
** @param fd filedescriptor to use
**
** @return {
** int : number of char writed
** }
**/
int prety_print(any_t *any, int fd);

/**
** @brief get unlimited nested data
**
** to get value of a dico : "d", "key"
** to get specific index array : "a", 2
** you can mix the two
** (any, "da", "key", 2)
**
** @param any any in wich the values are
** @param format format to use
** @param ... unlimited arguments
**
** @return {
** NULL : any or format is NULL,
** NULL : the value don't exists,
** any_t *: the value asked
** }
**/
any_t *get_from_any(any_t *any, char const *format, ...);

/**
** @brief get any_t from a dico_t (cast void * of dico_t value)
**
** @param dico dico in which the key are
** @param key key to represent the value
**
** @return {
** NULL : dico or key is NULL,
** NULL : the key don't exists
** any_t *: the value asked
** }
**/
any_t *dico_t_get_any(dico_t *dico, char const *key);

/**
** @brief write any_t to a json file
**
** @param any any to write
** @param path path to a file that will be override
**
** @return status under the form of the enum
**/
enum json_status_err_e write_json(any_t *any, char const *path);

/**
** @brief destroy any
**
** @param data any_t to destroy
**/
void destroy_any(void *data);

/**
** @brief parse any_t to a char **
**
** @param array any_t in which the array of char * is
**
** @return {
** NULL : array is NULL,
** NULL : array contains other than char *,
** char **: the values asked (array of char *)
** }
**/
char **get_any_string_array(any_t *array);

/**
** @brief parse any_t to a int *
**
** @param array any_t in which the array int is
**
** @return {
** NULL : array is NULL,
** NULL : array contains other than int
** int *: the values asked (array of int)
** }
**/
int *get_any_int_array(any_t *array);

/**
** @brief parse any_t to a float *
**
** @param array any_t in which the array float is
**
** @return {
** NULL : array is NULL,
** NULL : array contains other than float,
** float *: the values asked (array of float)
** }
**/
float *get_any_float_array(any_t *array);

/**
** @brief create an empty any (useful to build a json)
**
** @return NULL if error; any_t * otherwise
**/
any_t *create_empty_json(void);

/**
** @brief add an any_t to the any dico
**
** @param root the root of the dico
** @param key the key
** @param any the any (take ownership of this parameter)
**
** @return the root
**/
any_t *creator_add_any(any_t *root, const char *key, any_t *any);

/**
** @brief add a number to the any dico
**
** @param root the root of the dico
** @param key the key
** @param number the number
**
** @return the root
**/
any_t *creator_add_int(any_t *root, const char *key, int number);

/**
** @brief add a number to the any dico
**
** @param root the root of the dico
** @param key the key
** @param number the number
**
** @return the root
**/
any_t *creator_add_float(any_t *root, const char *key, float number);

/**
** @brief add a string to the any dico
**
** @param root the root of the dico
** @param key the key
** @param string the string
**
** @return the root
**/
any_t *creator_add_string(any_t *root, const char *key, const char *string);

/**
** @brief add an array to the any dico
**
** @param root the root of the dico
** @param key the key
** @param arr the array (take ownership of this parameter)
**
** @return the root
**/
any_t *creator_add_array(any_t *root, const char *key, list_t *arr);

#endif
