/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for dynamic
** arrays used in the library.
*/

#ifndef LIB_CARPET_UTILS_ARRAY_H
    #define LIB_CARPET_UTILS_ARRAY_H
    #include <carpet/types.h>

    #define CRPT_ARRAY_INIT_CAP 8
    #define CRPT_ARRAY_GROWTH 1.5f


struct carpet_array {
    void **data;
    size_t count;
    size_t capacity;
};


void crpt_array_append(crpt_array_t *array, void *data);
void crpt_array_delete(crpt_array_t *array, NULLABLE free_fnc_t free);
void crpt_array_reserve(crpt_array_t *array, size_t count);


#endif
