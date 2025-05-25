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
    soldier->state_time = 0;
    soldier->state = ES_DEAD;
    soldier->frame = 0;
    soldier->frame_time = 0;
    soldier->object.type = OT_DEAD_ENEMY;
}
