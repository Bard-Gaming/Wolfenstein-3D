/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_soldier
*/

#include "carpet/utils/vector.h"
#include <wolf/enemy.h>
#include <wolf/player.h>


/*
** Updates the soldier to face the
** player.
*/
static void face_player(enemy_t *soldier)
{
    vec2_t dir = crpt_vec2_sub(*get_player()->pos, soldier->object.position);

    soldier->rotation = atan2(dir.y, dir.x);
}

/*
** Determines whether or not the player is
** in the line of sight of the given soldier
** or not.
*/
static int player_is_visible(const enemy_t *soldier)
{
    player_t *player = get_player();
    vec2_t forward = { cos(soldier->rotation), - sin(soldier->rotation) };
    vec2_t dir_to_player = crpt_vec2_normalized(
        crpt_vec2_sub(*player->pos, soldier->object.position)
    );

    return crpt_vec2_dot(forward, dir_to_player) > 0.7;
}


/*
** Makes the soldier move forward.
*/
static void move_forward(enemy_t *soldier)
{
    const double speed = 0.6;
    vec2_t offset = crpt_vec2_normalized((vec2_t){
        .x = cos(soldier->rotation),
        .y = - sin(soldier->rotation),
    });

    offset = crpt_vec2_scale(offset, speed);
    soldier->object.position = crpt_vec2_add(soldier->object.position, offset);
}

/*
** Handles the idle state for the soldier
*/
static void handle_idle_state(enemy_t *soldier)
{
    if (player_is_visible(soldier))
        return set_soldier_state(soldier, ES_ATTACK);
    if (soldier->state_time > soldier->state_duration)
        return set_soldier_state(soldier, ES_MOVE);
}

/*
** Handles the move state for the soldier.
*/
static void handle_move_state(enemy_t *soldier)
{
    if (player_is_visible(soldier))
        return set_soldier_state(soldier, ES_ATTACK);
    if (soldier->state_time > soldier->state_duration)
        return set_soldier_state(soldier, ES_IDLE);
    if (soldier->state_time == 1)
        soldier->rotation = ((double)crpt_rand(1000) / 1000.0) * M_2PI;
    move_forward(soldier);
}

/*
** Handles the enemy's attack state.
*/
static void handle_attack_state(enemy_t *soldier)
{
    player_t *player = get_player();
    double distance =
        crpt_vec2_distance(*player->pos, soldier->object.position);

    if (distance > 50.0)
        return set_soldier_state(soldier, ES_MOVE);
    face_player(soldier);
    if (soldier->state_time % 100 == 0)
        hurt_player(2.5);
}

void update_soldier(enemy_t *soldier)
{
    soldier->state_time++;
    switch (soldier->state) {
    case ES_IDLE:
        return handle_idle_state(soldier);
    case ES_MOVE:
        return handle_move_state(soldier);
    case ES_ATTACK:
        return handle_attack_state(soldier);
    default:
        return;
    }
}
