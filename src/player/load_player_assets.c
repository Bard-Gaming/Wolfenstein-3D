/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_player_assets
*/

#include <wolf/player.h>


/*
** Loads a player asset.
** The 'height' constant reflects
** the height of the weapon when
** in the hand of the player (in px).
*/
static void load_asset(const char *path, const char *id)
{
    const float height = 1280.f;
    vec2u_t size = crpt_camera_get_size();
    sprite_t *sprite;

    crpt_load_texture(path, id);
    crpt_load_sprite(crpt_fetch_texture(id), id);
    sprite = crpt_fetch_sprite(id);
    sfSprite_setTextureRect(sprite, (sfIntRect){ 0, 0, 64, 64 });
    sfSprite_setScale(sprite, (sfVector2f){ size.x / 64.f, height / 64.f });
    sfSprite_setPosition(sprite, (sfVector2f){ 0.f, size.y - height });
}

/*
** Loads the player's assets.
*/
void load_player_assets(void)
{
    load_asset("assets/sprites/player/pistol.png", "player_pistol");
}
