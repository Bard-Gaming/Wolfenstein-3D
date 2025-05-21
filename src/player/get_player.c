/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** get_player
*/

#include <wolf/player.h>


/*
** Player getter function.
*/
player_t *get_player(void)
{
    static player_t player = { 0 };

    return &player;
}
