/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_soldier_state
*/

#include <wolf/enemy.h>


/*
** Updates the state of the given
** soldier to the state specified
** as argument.
*/
void set_soldier_state(enemy_t *soldier, enemy_state_t state)
{
    soldier->state_time = 0;
    soldier->state = state;
    update_soldier_texture(soldier);
}
