/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** init_player
*/

#include <wolf/player.h>


/*
** Initializes the player.
** Call this function when loading a level.
*/
void init_player(void)
{
    player_t *player = get_player();

    player->health = PLAYER_MAX_HEALTH;
    player->pos = crpt_camera_get_position();
    player->ammo = PLAYER_START_AMMO;
    player->shoot_delay = 0.0;
    player->weapon = WT_PISTOL;
}
