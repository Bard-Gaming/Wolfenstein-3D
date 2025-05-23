/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crealloc
*/

#include <carpet/memory.h>
#include <carpet/errno.h>
#include <stdlib.h>


/*
** Carpet library's realloc wrapper.
** This handles failing memory allocations
** by exiting the program.
** See cmalloc for more information on this
** decision.
*/
void *crealloc(void *ptr, size_t size)
{
    void *res = realloc(ptr, size);

    if (size > 0 && res == NULL) {
        crpt_errno_set(CE_NO_MEMORY);
        crpt_perror("carpet");
        exit(CRPT_CRITICAL_ERROR);
    }
    return res;
}
