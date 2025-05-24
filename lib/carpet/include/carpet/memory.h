/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for all
** memory related utilities
*/

#ifndef LIB_CARPET_MEMORY_H
    #define LIB_CARPET_MEMORY_H
    #include <carpet/types.h>


void *cmalloc(size_t size);
void *ccalloc(size_t nmemb, size_t size);
void *crealloc(void *NULLABLE ptr, size_t size);


#endif
