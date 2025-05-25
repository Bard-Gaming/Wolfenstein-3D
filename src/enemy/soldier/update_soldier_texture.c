/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_soldier_texture
*/

#include <wolf/enemy.h>
#include <string.h>
#include <stdio.h>


const char *get_state_str(enemy_t *soldier)
{
    switch (soldier->state) {
        case ES_IDLE:
            return "idle";
        case ES_MOVE:
            return "move";
        case ES_ATTACK:
            return "shoot";
        default:
            return "idle";
    }
}

const char *get_direction_str(double rotation)
{
    double deg = rotation * (180.0 / M_PI);

    if (deg >= 337.5 || deg < 22.5)
        return "front";
    if (deg < 67.5)
        return "front_right";
    if (deg < 112.5)
        return "right";
    if (deg < 157.5)
        return "back_right";
    if (deg < 202.5)
        return "back";
    if (deg < 247.5)
        return "back_left";
    if (deg < 292.5)
        return "left";
    return "front_left";
}

void update_animation_frame(enemy_t *soldier)
{
    unsigned int total_frames = (soldier->state == ES_ATTACK) ? 3 : 4;

    soldier->frame_time++;
    if (soldier->frame_time >= SOLDIER_FRAME_TIME) {
        soldier->frame_time = 0;
        soldier->frame = (soldier->frame + 1) % total_frames;
    }
}

void apply_texture(enemy_t *soldier, const char *texture_id)
{
    texture_t *texture = crpt_fetch_texture(texture_id);
    vec2_t rect = {
        soldier->frame * 64.0,
        (soldier->frame + 1) * 64.0,
    };

    soldier->object.texture = texture;
    soldier->object.texture_rect = rect;
}

void update_soldier_texture(enemy_t *soldier)
{
    const char *state = get_state_str(soldier);
    const char *dir = get_direction_str(soldier->rotation);
    char texture_id[128];

    if (soldier->state != ES_ATTACK)
        snprintf(texture_id, 128, "%s_%s", state, dir);
    else
        strcpy(texture_id, "shoot");
    update_animation_frame(soldier);
    apply_texture(soldier, texture_id);
}
