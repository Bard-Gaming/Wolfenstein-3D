/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** player_use_weapon
*/

#include <wolf/player.h>
#include <wolf/enemy.h>


/*
** Plays the audio the player's weapon
** makes when there is no ammo left.
** TODO: Add the actual sound lol
*/
static void no_ammo(player_t *player)
{
    player->anim_frame = 3;
}

/*
** Actual weapon shooting logic.
*/
static void shoot_weapon(player_t *player)
{
    const map_t *map = crpt_game_get()->scene->map;
    enemy_t *enemy = (void *)crpt_ray_hitscan_object(
        map, crpt_camera_get_rotation(), OT_ENEMY
    );

    if (enemy == NULL)
        return;
    hurt_enemy(enemy, weapon_lookup[player->weapon].damage);
}

/*
** Makes the player use their weapon.
*/
void player_use_weapon(void)
{
    player_t *player = get_player();

    if (player->shoot_delay > 0.0)
        return;
    player->is_anim = true;
    player->time_elapsed = 10;
    player->shoot_delay = weapon_lookup[player->weapon].cooldown;
    if (player->ammo == 0)
        return no_ammo(player);
    player->ammo--;
    shoot_weapon(player);
}
