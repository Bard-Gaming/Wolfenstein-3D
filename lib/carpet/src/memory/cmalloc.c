/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** cmalloc
*/

#include <carpet/memory.h>
#include <carpet/errno.h>
#include <stdlib.h>


/*
** Carpet library's memory allocation
** function.
** This handles failing memory allocations
** by exiting the program (not being able
** to allocate memory means there is a critical
** problem which this library can't handle).
*/
void *cmalloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL) {
        crpt_errno_set(CE_NO_MEMORY);
        crpt_perror("carpet");
        exit(CRPT_CRITICAL_ERROR);
    }
    return ptr;
}
