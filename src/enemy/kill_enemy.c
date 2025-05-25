/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** kill_enemy
*/

#include <wolf/enemy.h>


/*
** Kills an enemy of an type.
*/
void kill_enemy(enemy_t *enemy)
{
    switch (enemy->type) {
    case ET_SOLDIER:
        return kill_soldier(enemy);
    case ET_UNSET:
        return;
    }
}
