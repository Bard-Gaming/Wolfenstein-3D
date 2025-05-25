/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_player_weapon
*/

#include <wolf/player.h>


/*
** Changes the player's weapon to the
** one specified as argument.
*/
void set_player_weapon(weapon_type_t weapon)
{
    player_t *player = get_player();

    player->weapon = weapon;
    player->shoot_delay = 0.0;
    player->anim_frame = 0;
    player->time_elapsed = 0;
    player->is_anim = false;
    player->weapon_sprite = crpt_fetch_sprite(weapon_lookup[weapon].asset_id);
}
