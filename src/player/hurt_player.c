/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** hurt_player
*/

#include <wolf/player.h>
#include <wolf/scenes.h>


/*
** Hurts the player by the given amount
** of damage.
** The player has a native 15% evasion rate.
*/
void hurt_player(double damage)
{
    player_t *player = get_player();

    if (crpt_rand(100) < 15)
        return;
    player->health = fmax(player->health - damage, 0.0);
    if (player->health <= 0.0)
        set_death_scene();
    player->hurt_time = 1.0;
}
