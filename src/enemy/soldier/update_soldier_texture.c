/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_soldier_texture
*/

#include <wolf/enemy.h>
#include <stdio.h>


static const char *get_state_str(const enemy_t *soldier)
{
    switch (soldier->state) {
        case ES_IDLE:
            return "idle";
        case ES_MOVE:
            return "move";
        case ES_ATTACK:
            return "shoot";
        case ES_DEAD:
            return "die";
        default:
            return "idle";
    }
}

static const double compute_angle(const enemy_t *soldier)
{
    return norm(
        soldier->rotation - crpt_camera_get_rotation()
    );
}

static const char *get_direction_str(const enemy_t *soldier)
{
    double deg = compute_angle(soldier) * (180.0 / M_PI);

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

static const char *get_texture_id(const enemy_t *soldier)
{
    static char texture_id[SOLDIER_TEXTURE_MAX];
    const char *state;
    const char *dir;

    switch (soldier->state) {
    case ES_DEAD:
        return "soldier_die";
    case ES_ATTACK:
        return "soldier_shoot";
    default:
        state = get_state_str(soldier);
        dir = get_direction_str(soldier);
        snprintf(texture_id, 128, "soldier_%s_%s", state, dir);
        return texture_id;
    }
}

static unsigned int get_total_frames(const enemy_t *soldier)
{
    switch (soldier->state) {
    case ES_ATTACK:
        return 4;
    case ES_MOVE:
        return 4;
    case ES_DEAD:
        return 5;
    default:
        return 1;
    }
}

static void update_animation_frame(enemy_t *soldier)
{
    unsigned int total_frames = get_total_frames(soldier);

    if (soldier->state == ES_ATTACK && soldier->frame == 3)
        return;
    soldier->frame_time++;
    if (soldier->frame_time >= SOLDIER_FRAME_TIME) {
        soldier->frame_time = 0;
        soldier->frame = (soldier->frame + 1) % total_frames;
    }
}

static void apply_texture(enemy_t *soldier, const char *texture_id)
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
    const char *texture_id = get_texture_id(soldier);

    update_animation_frame(soldier);
    apply_texture(soldier, texture_id);
    soldier->object.color = soldier->hurt_time == 0 ?
        sfWhite : sfRed;
}
