/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_player_fixed
*/

#include <wolf/player.h>


/*
** Increments the player's current
** weapon animation frame.
*/
static void increment_animation_frame(player_t *player)
{
    sfIntRect frame_rect = { .width = 64, .height = 64, .top = 0 };

    player->anim_frame = (player->anim_frame + 1) % 5;
    if (player->anim_frame == 0)
        player->is_anim = false;
    frame_rect.left = 64 * player->anim_frame;
    player->time_elapsed = 0;
    sfSprite_setTextureRect(player->weapon_sprite, frame_rect);
}

/*
** Runs the player's fixed update
** function.
** This mainly handles animations, and
** other time-sensitive things.
*/
void update_player_fixed(void)
{
    player_t *player = get_player();

    if (!player->is_anim)
        return;
    player->time_elapsed++;
    if (player->time_elapsed >= 7)
        increment_animation_frame(player);
}
