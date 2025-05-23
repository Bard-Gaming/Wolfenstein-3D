/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_enemy_max_health
*/

#include <wolf/enemy.h>


/*
** Sets the enemy's max health to the
** given value.
*/
void set_enemy_max_health(enemy_t *enemy, double health)
{
    enemy->max_health = health;
    enemy->health = health;
}
