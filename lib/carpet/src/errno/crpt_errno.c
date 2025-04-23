/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_errno_get &&
** crpt_errno_set
*/

#include <carpet/errno.h>


/*
** Getter for the internal errno variable.
** This function is marked static as the
** only interaction with the errno pointer
** should be with the getter & setter functions.
*/
static crpt_errno_t *get_errno_ptr(void)
{
    static crpt_errno_t errno = CE_NONE;

    return &errno;
}

/*
** Getter function for the library's internal
** errno variable.
*/
crpt_errno_t crpt_errno_get(void)
{
    return *get_errno_ptr();
}

/*
** Setter function for the library's internal
** errno variable.
*/
void crpt_errno_set(crpt_errno_t error)
{
    *get_errno_ptr() = error;
}
