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
        .controls[CK_FRONT] = sfKeyZ, .controls[CK_BACK] = sfKeyS,
        .controls[CK_LEFT] = sfKeyQ, .controls[CK_RIGHT] = sfKeyD,
        .controls[CK_SPRINT] = sfKeyLShift, .controls[CK_SHOOT] = sfKeyX,
        .controls[CK_WEAPON_NEXT] = sfKeyE, .controls[CK_WEAPON_PREV] = sfKeyA,
        .sensitivity = SENSITIVITY_DEFAULT,
    };

    return &settings;
}
