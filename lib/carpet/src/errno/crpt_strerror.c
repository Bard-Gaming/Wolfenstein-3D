/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_strerror
*/

#include <carpet/errno.h>


static const char *crpt_strerror_buffer[CE_COUNT] = {
    [CE_NONE] = "no error set.",

    // Asset manager:
    [CE_AM_REUSED_ID] = "attempted to assign a new asset to an existing id.",
    [CE_AM_INVALID_ID] = "unknown asset id.",
    [CE_AM_LOAD_FAIL] = "failed to load asset.",

    // Game:
    [CE_GAME_NO_INIT] = "game hasn't been initialized.",
    [CE_GAME_DOUBLE_INIT] = "game has already been initialized.",

    // Object:
    [CE_OBJECT_NO_MAP] = "tried creating object on scene with no map.",

    // Miscellaneous:
    [CE_NO_MEMORY] = "critical memory error.",
};


/*
** Returns a string which describes the
** given error.
** The returned string is a string literal
** and may not be changed or passed to free().
*/
const char *crpt_strerror(crpt_errno_t error)
{
    return crpt_strerror_buffer[error];
}
