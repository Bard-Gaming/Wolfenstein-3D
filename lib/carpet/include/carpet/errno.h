/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for everything
** related to errors / error
** handling
*/

#ifndef LIB_CARPET_ERRNO_H
    #define LIB_CARPET_ERRNO_H
    #include <carpet/types.h>

    #define CRPT_ERRNO crpt_errno_get()
    #define CRPT_CRITICAL_ERROR 126


enum carpet_errno {
    CE_NONE,

    // Asset manager errors:
    CE_AM_REUSED_ID,
    CE_AM_INVALID_ID,
    CE_AM_LOAD_FAIL,

    // Game errors:
    CE_GAME_NO_INIT,
    CE_GAME_DOUBLE_INIT,

    // Map:
    CE_MAP_INVALID_FILE,

    // Object errors:
    CE_OBJECT_NO_MAP,

    // Miscellaneous:
    CE_NO_MEMORY,

    CE_COUNT,  // keep last
};


// User functions:
void crpt_perror(const char *prefix);
const char *crpt_strerror(crpt_errno_t error);

// Internal functions:
crpt_errno_t crpt_errno_get(void);
void crpt_errno_set(crpt_errno_t error);


#endif
