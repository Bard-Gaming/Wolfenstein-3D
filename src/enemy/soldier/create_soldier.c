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
enemy_t *create_soldier(double x, double y)
{
    enemy_t *soldier = create_enemy(
        crpt_fetch_texture("soldier_idle_front"),
        (vec2_t){ x, y }
    );

    set_enemy_max_health(soldier, 20);
    soldier->object.update = (object_update_fnc_t)update_soldier;
    soldier->type = ET_SOLDIER;
    set_soldier_state(soldier, ES_IDLE);
    return soldier;
}
