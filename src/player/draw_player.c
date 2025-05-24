/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** draw_player
*/

#include <wolf/player.h>


/*
** Draws the player's arms and other
** related elements.
*/
void draw_player(void)
{
    crpt_draw_sprite(crpt_fetch_sprite("player_pistol"));
}
