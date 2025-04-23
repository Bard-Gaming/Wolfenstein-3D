/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** ccalloc
*/

#include <carpet/memory.h>
#include <carpet/errno.h>
#include <stdlib.h>


/*
** Carpet library's calloc wrapper.
** This handles failing memory allocations
** by exiting the program.
** See cmalloc for more information on why.
*/
void *ccalloc(size_t nmemb, size_t size)
{
    void *ptr = calloc(nmemb, size);

    if (ptr == NULL) {
        crpt_errno_set(CE_NO_MEMORY);
        crpt_perror("carpet");
        exit(CRPT_CRITICAL_ERROR);
    }
    return ptr;
}
