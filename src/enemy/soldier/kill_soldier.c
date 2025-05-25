/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** kill_soldier
*/

#include <wolf/enemy.h>


/*
** Kills a soldier.
** This initiates the death sequence.
*/
void kill_soldier(enemy_t *soldier)
{
    soldier->hurt_time = 0;
    soldier->object.texture = crpt_fetch_texture("soldier_die");
    soldier->object.texture_rect = (vec2_t){ 0.0, 64.0 };
    soldier->object.type = OT_DEAD_ENEMY;
}
