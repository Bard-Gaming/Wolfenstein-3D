/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** is_key_pressed
*/

#include <wolf/settings.h>


/*
** Determines whether or not the given
** control key is pressed.
** This function is preferred over manually
** checking a real key with the SFML library,
** as this allows the player to customize their
** control bindings (i.e. this uses a key tied to
** an action, rather than a physical key on the
** keyboard).
*/
bool is_key_pressed(control_key_t key)
{
    settings_t *settings = get_settings();

    return sfKeyboard_isKeyPressed(settings->controls[key]);
}
