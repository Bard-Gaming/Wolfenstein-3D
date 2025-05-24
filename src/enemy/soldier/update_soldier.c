/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_soldier
*/

#include <carpet/utils/vector.h>
#include <wolf/player.h>
#include <wolf/enemy.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define SECONDS(x) ((x) * 100)
#define RAND_SECONDS(min, max) (rand() % (SECONDS(max) - SECONDS(min) + 1) + SECONDS(min))


static void face_player(enemy_t *soldier)
{
    player_t *player = get_player();
    vec2_t dir = crpt_vec2_sub(*player->pos, soldier->object.position);
    soldier->rotation = atan2(dir.y, dir.x);
    double deg = soldier->rotation * 180 / M_PI;

    if (deg < 0)
        deg += 360;
    printf("[DEBUG] Soldier rotation set to face player: %.2f°\n", deg);
}

static int is_player_in_front(enemy_t *soldier)
{
    player_t *player = get_player();
    vec2_t dir_to_player = crpt_vec2_sub(*player->pos, soldier->object.position);
    vec2_t forward = { cos(soldier->rotation), sin(soldier->rotation) };
    vec2_t normal = crpt_vec2_normalized(dir_to_player);
    double dot = crpt_vec2_dot(forward, normal);
    double angle_to_player = atan2(normal.y, normal.x) * 180 / M_PI;
    double soldier_angle = soldier->rotation * 180 / M_PI;

    printf("hereeeeeeeeeeeeeeeeeee %lf\n", soldier->rotation);
    if (angle_to_player < 0)
        angle_to_player += 360;
    if (soldier_angle < 0)
        soldier_angle += 360;
    printf("[DEBUG] Facing: %.2f°, Player Dir: %.2f°, Dot: %.2f\n",
           soldier_angle, angle_to_player, dot);
    return dot > 0.7;
}

static void move_forward(enemy_t *soldier)
{
    double speed = 0.1;
    double dx = cos(soldier->rotation) * speed;
    double dy = sin(soldier->rotation) * speed;

    soldier->object.position.x += dx;
    soldier->object.position.y += dy;

    printf("[DEBUG] Soldier moves (%.2f, %.2f) → new pos: (%.2f, %.2f)\n",
        dx, dy,
        soldier->object.position.x,
        soldier->object.position.y);
}

void update_bool should_switch_to_attack(enemy_t *soldier)
{
    if (soldier->state != ES_ATTACK && is_player_in_front(soldier)) {
        printf("[DEBUG] Switching to ATTACK (player in sight)\n");
        set_soldier_state(soldier, ES_ATTACK);
        return true;
    }
    return false;
}

void handle_idle_state(enemy_t *soldier)
{
    if (soldier->state_time == 1) {
        printf("[DEBUG] State = IDLE\n");
        face_player(soldier);
    }

    if (soldier->state_time > RAND_SECONDS(2, 4)) {
        printf("[DEBUG] Switching to MOVE\n");
        set_soldier_state(soldier, ES_MOVE);
    }
}

void handle_move_state(enemy_t *soldier)
{
    if (soldier->state_time == 1) {
        printf("[DEBUG] State = MOVE\n");
        face_player(soldier);
    }

    move_forward(soldier);

    if (soldier->state_time > RAND_SECONDS(1, 2)) {
        printf("[DEBUG] Switching to IDLE\n");
        set_soldier_state(soldier, ES_IDLE);
    }
}

void handle_attack_state(enemy_t *soldier)
{
    if (soldier->state_time == 1)
        printf("[DEBUG] State = ATTACK\n");

    if (!is_player_in_front(soldier)) {
        printf("[DEBUG] Lost player — back to IDLE\n");
        set_soldier_state(soldier, ES_IDLE);
    }
    else if (soldier->state_time % SECONDS(1) == 0) {
        printf("[DEBUG] ATTACKING player!\n");
        // TODO: damage or shoot
    }
}

void update_soldier(enemy_t *soldier)
{
    soldier->state_time++;

    if (should_switch_to_attack(soldier))
        return;
    switch (soldier->state) {
        case ES_IDLE:
            handle_idle_state(soldier);
            break;
        case ES_MOVE:
            handle_move_state(soldier);
            break;
        case ES_ATTACK:
            handle_attack_state(soldier);
            break;
    }
}
