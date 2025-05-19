/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_scene_default_update
*/

#include <carpet/scene.h>
#include <carpet/ray.h>
#include <carpet/map.h>
#include <carpet/game.h>
#include <carpet/utils/vector.h>


/*
** Updates the movement based on the
** camera's rotation and the given intensity.
*/
static vec2_t compute_pos_offset(camera_t *camera, float intensity)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        intensity *= 4.f;
        if (camera->fov < M_PI_2 + 0.15)
            camera->fov += 0.01;
    } else {
        if (camera->fov > M_PI_2)
            camera->fov -= 0.01;
    }
    return (vec2_t){
        .x = cosf(camera->rotation) * intensity,
        .y = - sinf(camera->rotation) * intensity,
    };
}

/*
** Corrects the player's movement if a collision
** occurred.
*/
static bool will_collide(const map_t *map, vec2_t pos, vec2_t offset)
{
    vec2_t new_pos = crpt_vec2_add(pos, crpt_vec2_mul(offset, 5.0f));

    return crpt_map_is_solid(map, new_pos);
}

static float get_input_diff(sfKeyCode a, sfKeyCode b)
{
    return
        sfKeyboard_isKeyPressed(a) -
        sfKeyboard_isKeyPressed(b);
}

float vec2f_dot(vec2_t a, vec2_t b)
{
    return a.x * b.x + a.y * b.y;
}

vec2_t vec2f_scale(vec2_t v, float s)
{
    return (vec2_t){v.x * s, v.y * s};
}

vec2_t vec2f_normalize(vec2_t v)
{
    float len = sqrtf(v.x * v.x + v.y * v.y);

    if (len == 0.0f)
        return (vec2_t){0.0f, 0.0f};
    return (vec2_t){v.x / len, v.y / len};
}

vec2_t get_wall_normal(const map_t *map, vec2_t pos)
{
    vec2_t normal = {0.0f, 0.0f};
    vec2_t up    = {0.0f, -1.0f};
    vec2_t down  = {0.0f,  1.0f};
    vec2_t left  = {-1.0f, 0.0f};
    vec2_t right = {1.0f,  0.0f};
    vec2_t neighbors[4] = {up, down, left, right};
    vec2_t check;

    for (int i = 0; i < 4; i++) {
        check = crpt_vec2_add(pos, neighbors[i]);
        if (crpt_map_is_solid(map, check)) {
            normal = crpt_vec2_add(normal, neighbors[i]);
        }
    }
    normal = vec2f_scale(normal, -1.0f);
    return vec2f_normalize(normal);
}

/*
** Carpet Lib's default scene's update function.
** This handle's the player's movement.
*/
void crpt_scene_default_update(scene_t *scene, time_micro_t dt)
{
    float mv_input = get_input_diff(sfKeyUp, sfKeyDown);
    float rotation = get_input_diff(sfKeyRight, sfKeyLeft) * 0.01f;
    camera_t *camera = &crpt_game_get()->camera;
    vec2_t offset = compute_pos_offset(camera, mv_input);
    static int i = 0;

    (void)dt;
    camera->rotation = norm(camera->rotation + rotation);
    if (will_collide(scene->map, camera->position, offset)) {
        vec2_t wall_normal = get_wall_normal(scene->map, camera->position);
        vec2_t glide = crpt_vec2_sub(offset, vec2f_scale(wall_normal, vec2f_dot(offset, wall_normal)));
        camera->position = crpt_vec2_add(camera->position, glide);
        //printf("collide %d\n", i++);
    } else {
        camera->position = crpt_vec2_add(camera->position, offset);
    }
}
