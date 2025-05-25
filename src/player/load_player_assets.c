/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_player_assets
*/

#include <wolf/player.h>


/*
** Loads a player weapon.
** The 'height' constant reflects
** the height of the weapon when
** in the hand of the player (in px).
*/
static void load_weapon(const char *path, const char *id)
{
    vec2u_t size = crpt_camera_get_size();
    const float scale = size.x / 128.f;
    sprite_t *sprite;

    crpt_load_texture(path, id);
    crpt_load_sprite(crpt_fetch_texture(id), id);
    sprite = crpt_fetch_sprite(id);
    sfSprite_setOrigin(sprite, (sfVector2f){ 0.f, 64.f });
    sfSprite_setTextureRect(sprite, (sfIntRect){ 0, 0, 64, 64 });
    sfSprite_setScale(sprite, (sfVector2f){ scale, scale * 0.75 });
    sfSprite_setPosition(sprite, (sfVector2f){ size.x * 0.25, size.y });
}

/*
** Loads the plain textures used in
** the UI of the player.
*/
static void load_textures(void)
{
    crpt_load_texture("assets/sprites/player/healthbar_full.png", "hb_full");
    crpt_load_texture("assets/sprites/player/healthbar_empty.png", "hb_empty");
}

/*
** Loads the player's assets.
*/
void load_player_assets(void)
{
    load_textures();
    load_weapon("assets/sprites/player/pistol.png", "player_pistol");
    load_weapon("assets/sprites/player/submachine.png", "player_submachine");
    load_weapon("assets/sprites/player/minigun.png", "player_minigun");
}
