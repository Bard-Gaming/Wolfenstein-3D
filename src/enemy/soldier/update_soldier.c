/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_soldier
*/

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

static bool collides_with_wall(vec2_t start, vec2_t direction)
{
    const map_t *map = crpt_game_get()->scene->map;
    vec2_t step = crpt_vec2_scale(direction, 0.1);
    vec2_t current = crpt_vec2_add(start, step);

    for (unsigned int i = 0; i < 20; i++) {
        if (crpt_map_is_solid(map, current))
            return true;
        current = crpt_vec2_add(current, step);
    }
    return false;
}

/*
** Makes the soldier move forward, if possible.
** Returns true if the move has been possible
** and false if not.
*/
static bool move_forward(enemy_t *soldier)
{
    const double speed = 0.6;
    vec2_t direction = crpt_vec2_normalized((vec2_t){
        cos(soldier->rotation),
        - sin(soldier->rotation),
    });
    vec2_t offset;

    if (collides_with_wall(soldier->object.position, direction))
        return false;
    offset = crpt_vec2_scale(direction, speed);
    soldier->object.position = crpt_vec2_add(soldier->object.position, offset);
    return true;
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
    if (!move_forward(soldier))
        set_soldier_state(soldier, ES_IDLE);
}

/*
** Handles the enemy's attack state.
*/
static void handle_attack_state(enemy_t *soldier)
{
    player_t *player = get_player();
    double distance =
        crpt_vec2_distance(*player->pos, soldier->object.position);

    if (distance > 500.0)
    /*     face_player(soldier); */
    /* if (!player_is_visible(soldier)) */
        return set_soldier_state(soldier, ES_MOVE);
    if (soldier->state_time % SOLDIER_SHOOT_CD == 0) {
        soldier->frame_time = 0;
        soldier->frame = 2;
        hurt_player(2.5);
    }
}

/*
** Runs a single cycle of the enemy's AI.
*/
static void run_enemy_ai(enemy_t *soldier)
{
    if (soldier->state == ES_DEAD && soldier->frame == 4)
        soldier->object.update = NULL;
    if (soldier->hurt_time > 0)
        soldier->hurt_time--;
    switch (soldier->state) {
    case ES_IDLE:
        return handle_idle_state(soldier);
    case ES_MOVE:
        handle_move_state(soldier);
        break;
    case ES_ATTACK:
        return handle_attack_state(soldier);
    default:
        return;
    }
}

/*
** Updates the given soldier's
** data.
*/
void update_soldier(enemy_t *soldier)
{
    run_enemy_ai(soldier);
    update_soldier_texture(soldier);
    soldier->state_time++;
}
