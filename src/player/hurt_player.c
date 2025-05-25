/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** hurt_player
*/

#include <wolf/player.h>


/*
** Hurts the player by the given amount
** of damage.
** TODO: Handle death
*/
void hurt_player(double damage)
{
    player_t *player = get_player();

    player->health = fmax(player->health - damage, 0.0);
}
