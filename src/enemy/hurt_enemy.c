/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** hurt_enemy
*/

#include <wolf/enemy.h>


/*
** Hurts an enemy of any type by
** the given damage. If the damage
** would kill the enemy, this kills
** the enemy instead.
*/
void hurt_enemy(enemy_t *enemy, double damage)
{
    if (enemy->health - damage < 0.0)
        return kill_enemy(enemy);
    switch (enemy->type) {
    case ET_SOLDIER:
        return hurt_soldier(enemy, damage);
    case ET_UNSET:
        return;
    }
}
