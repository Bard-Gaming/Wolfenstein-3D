/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** hurt_soldier
*/

#include <wolf/enemy.h>


/*
** Hurts the given soldier by
** the damage given as argument.
** Soldiers don't have armor, so
** the damage is applied as is.
*/
void hurt_soldier(enemy_t *soldier, double damage)
{
    soldier->health -= damage;
    soldier->object.color = sfRed;
    soldier->hurt_time = SOLDIER_HURT_TIME;
}
