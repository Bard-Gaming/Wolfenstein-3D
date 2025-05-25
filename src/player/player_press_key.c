/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** player_press_key
*/

#include <wolf/player.h>
#include <wolf/settings.h>


/*
** Switches to the weapon with
** the given offset.
*/
static void weapon_switch(int offset)
{
    weapon_type_t weapon =
        (get_player()->weapon + offset + WT_COUNT) %
        WT_COUNT;

    set_player_weapon(weapon);
}

/*
** Player's key event handler function.
** Note: This shouldn't be used for movement.
** See the update_player() function for those.
*/
void player_press_key(event_t *event)
{
    settings_t *settings = get_settings();

    if (event->key.code == settings->controls[CK_WEAPON_NEXT])
        return weapon_switch(1);
    if (event->key.code == settings->controls[CK_WEAPON_PREV])
        return weapon_switch(-1);
}
