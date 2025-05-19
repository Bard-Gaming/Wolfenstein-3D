/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_level_scene
*/

#include <wolf/scenes.h>


/*
** Updates the movement based on the
** camera's rotation and the given intensity.
*/
static vec2_t compute_pos_offset(camera_t *camera, float intensity)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        intensity *= 4.f;
        if (camera->fov < M_PI_2 + 0.075)
            camera->fov += 0.0075;
    } else {
        if (camera->fov > M_PI_2)
            camera->fov -= 0.0075;
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
    vec2_t new_pos = crpt_vec2_add(pos, crpt_vec2_scale(offset, 5.0f));

    return crpt_map_is_solid(map, new_pos);
}

static float get_input_diff(sfKeyCode a, sfKeyCode b)
{
    return
        sfKeyboard_isKeyPressed(a) -
        sfKeyboard_isKeyPressed(b);
}

/*
** Computes the normal vector of the given wall.
*/
vec2_t get_wall_normal(const map_t *map, vec2_t pos)
{
    vec2_t normal = { 0.0, 0.0 };
    vec2_t right = { 1.0, 0.0 };
    vec2_t left = { -1.0, 0.0 };
    vec2_t down = { 0.0, 1.0 };
    vec2_t up = { 0.0, -1.0 };
    vec2_t neighbors[] = {up, down, left, right};
    vec2_t check;

    for (unsigned int i = 0; i < 4; i++) {
        check = crpt_vec2_add(pos, neighbors[i]);
        if (crpt_map_is_solid(map, check))
            normal = crpt_vec2_add(normal, neighbors[i]);
    }
    crpt_vec2_scale(normal, -1.0);
    return crpt_vec2_normalized(normal);
}

static vec2_t compute_collision_vector(vec2_t offset,
    scene_t *scene, const camera_t *cam)
{
    vec2_t normal = get_wall_normal(scene->map, cam->position);

    normal = crpt_vec2_scale(normal, crpt_vec2_dot(offset, normal));
    return crpt_vec2_sub(offset, normal);
}

/*
** Updates the level's scene.
** Nothing much to add there, is there?..
*/
void update_level_scene(scene_t *scene, time_micro_t dt)
{
    float mv_input = get_input_diff(sfKeyUp, sfKeyDown);
    float rotation = get_input_diff(sfKeyRight, sfKeyLeft) * 0.01f;
    camera_t *camera = &crpt_game_get()->camera;
    vec2_t offset = compute_pos_offset(camera, mv_input);

    (void)dt;
    camera->rotation = norm(camera->rotation + rotation);
    if (will_collide(scene->map, camera->position, offset))
        offset = compute_collision_vector(offset, scene, camera);
    camera->position = crpt_vec2_add(camera->position, offset);
}
