/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** get_settings
*/

#include <wolf/settings.h>


/*
** Retrieves the game's settings.
*/
settings_t *get_settings(void)
{
    static settings_t settings = {
        .controls[0] = sfKeyZ, .controls[1] = sfKeyS,
        .controls[2] = sfKeyQ, .controls[3] = sfKeyD,
        .controls[4] = sfKeyLShift,
    };

    return &settings;
}
