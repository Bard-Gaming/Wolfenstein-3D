/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_player_assets
*/

#include <wolf/player.h>


/*
** Unloads a player asset.
*/
static void unload_asset(const char *id)
{
    crpt_unload_texture(id);
    crpt_unload_sprite(id);
}

/*
** Unloads the plain
*/
static void unload_textures(void)
{
    crpt_unload_texture("hb_full");
    crpt_unload_texture("hb_empty");
}

/*
** Unloads the player's assets
** and plain textures.
*/
void unload_player_assets(void)
{
    unload_textures();
    unload_asset("player_pistol");
}
