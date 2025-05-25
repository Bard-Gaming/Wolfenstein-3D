/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** set_soldier_state
*/

#include <wolf/enemy.h>


/*
** Min/Max pairs of state durations.
*/
static const vec2u_t state_durations[] = {
    [ES_IDLE] = { 50, 150 },
    [ES_MOVE] = { 50, 150 },
    [ES_ATTACK] = { 0, 0 },
    [ES_DEAD] = { 0, 0 },
};


/*
** Returns a random state duration between
** the given state's min and max.
*/
static unsigned int get_random_time(enemy_state_t state)
{
    if (state_durations[state].y == 0)
        return 0;
    return
        crpt_rand(state_durations[state].y) +
        state_durations[state].x;
}

/*
** Updates the state of the given
** soldier to the state specified
** as argument for the given
** duration.
*/
void set_soldier_state(enemy_t *soldier, enemy_state_t state)
{
    soldier->state = state;
    soldier->state_time = 0;
    soldier->state_duration = get_random_time(state);
    soldier->frame = 0;
    soldier->frame_time = 0;
}
