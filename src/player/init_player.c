/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** init_player
*/

#include <wolf/player.h>
#include <string.h>


/*
** Initializes the player.
** Call this function when loading a level.
*/
void init_player(void)
{
    player_t *player = get_player();
    sfText *ammo_display = player->ammo_display;

    memset(player, 0, sizeof(player_t));
    player->ammo_display = ammo_display;
    player->health = PLAYER_MAX_HEALTH;
    player->pos = crpt_camera_get_position();
    player->ammo = PLAYER_START_AMMO;
    set_player_weapon(WT_PISTOL);
}
