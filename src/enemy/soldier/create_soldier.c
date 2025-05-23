/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** create_soldier
*/

#include <wolf/enemy.h>


/*
** Creates a solider enemy at the
** given position.
*/
enemy_t *create_soldier(vec2_t pos)
{
    enemy_t *enemy = create_enemy(
        crpt_fetch_texture("soldier_idle_front"),
        pos
    );

    set_enemy_max_health(enemy, 20);
    enemy->object.update = (object_update_fnc_t)update_soldier;
    return enemy;
}
