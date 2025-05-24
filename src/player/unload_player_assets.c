/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_player_assets
*/

#include <wolf/player.h>


/*
** Loads a player asset.
*/
static void unload_asset(const char *id)
{
    crpt_unload_texture(id);
    crpt_unload_sprite(id);
}

/*
** Loads the player's assets.
*/
void unload_player_assets(void)
{
    unload_asset("player_pistol");
}
