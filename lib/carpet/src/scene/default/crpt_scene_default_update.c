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

/*
** Carpet Lib's default scene's update function.
** This handle's the player's movement.
*/
void crpt_scene_default_update(scene_t *scene, time_micro_t dt)
{
    float mv_input = get_input_diff(sfKeyZ, sfKeyS);
    float rotation = get_input_diff(sfKeyD, sfKeyQ) * 0.01f;
    camera_t *camera = &crpt_game_get()->camera;
    vec2_t offset = compute_pos_offset(camera, mv_input);

    (void)dt;
    camera->rotation = norm(camera->rotation + rotation);
    if (!will_collide(scene->map, camera->position, offset))
        camera->position = crpt_vec2_add(camera->position, offset);
}
