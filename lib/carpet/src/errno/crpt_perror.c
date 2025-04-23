/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_perror
*/

#include <carpet/errno.h>
#include <stdio.h>


/*
** Prints the currently set error in a
** given format to the standard error
** output.
** If the prefix parameter is NULL, the
** error message will be displayed normally.
** Otherwise, the error message will be printed
** in the format "<prefix>: <error>".
*/
void crpt_perror(const char *prefix)
{
    const char *repr = crpt_strerror(CRPT_ERRNO);

    if (prefix == NULL)
        fprintf(stderr, "error: %s\n", repr);
    else
        fprintf(stderr, "%s: error: %s\n", prefix, repr);
}
