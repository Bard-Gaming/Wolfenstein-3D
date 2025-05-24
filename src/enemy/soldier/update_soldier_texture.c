/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_soldier_texture
*/

#include <wolf/enemy.h>
#include <math.h>
#include <stdio.h>

#define SECONDS(x) ((x) * 100)
#define FRAME_WIDTH      64
#define FRAME_HEIGHT     64
#define FRAME_DURATION   SECONDS(0.2)

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

    if (deg < 0) deg += 360;
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

int get_total_frames(enemy_t *soldier)
{
    return (soldier->state == ES_ATTACK) ? 3 : 4;
}

sfIntRect get_frame_rect(int frame_index)
{
    return (sfIntRect) {
        .left = frame_index * FRAME_WIDTH,
        .top = 0,
        .width = FRAME_WIDTH,
        .height = FRAME_HEIGHT
    };
}

void advance_animation_frame(enemy_t *soldier, int total_frames)
{
    soldier->frame_time++;
    if (soldier->frame_time >= FRAME_DURATION) {
        soldier->frame_time = 0;
        soldier->frame = (soldier->frame + 1) % total_frames;
    }
}

void apply_sprite_texture(enemy_t *soldier, const char *texture_id, sfIntRect rect)
{
    texture_t *texture = crpt_fetch_texture(texture_id);

    soldier->object.texture = texture;
    //sfSprite_setTextureRect(soldier->object, rect);
    printf("[DEBUG] Texture: %s | Frame: %d | Rect.left: %d\n",
           texture_id, soldier->frame, rect.left);
}

void update_soldier_texture(enemy_t *soldier)
{
    const char *state = get_state_str(soldier);
    const char *dir = (soldier->state == ES_ATTACK) ? NULL : get_direction_str(soldier->rotation);
    char texture_id[128];
    int total_frames = get_total_frames(soldier);
    sfIntRect rect;

    if (dir)
        snprintf(texture_id, sizeof(texture_id), SOLDIER_ASSET("%s_%s"), state, dir);
    else
        snprintf(texture_id, sizeof(texture_id), SOLDIER_ASSET("shoot"));
    advance_animation_frame(soldier, total_frames);
    rect = get_frame_rect(soldier->frame);
    apply_sprite_texture(soldier, texture_id, rect);
}
