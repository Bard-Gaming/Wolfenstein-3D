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
static vec2_t compute_pos_offset(double intensity)
{
    double rotation = crpt_camera_get_rotation();

    return (vec2_t){
        .x = cosf(rotation) * intensity,
        .y = - sinf(rotation) * intensity,
    };
}

/*
** Checks whether or not the player will collide
** if he moves by the given offset.
*/
static bool will_collide(const map_t *map, vec2_t pos, vec2_t offset)
{
    vec2_t new_pos = crpt_vec2_add(pos, crpt_vec2_scale(offset, 6.0f));

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
    vec2_t check;
    vec2_t normal = { 0.0, 0.0 };
    vec2_t neighbors[] = {
        { map->cell_size, 0.0 },
        { - map->cell_size, 0.0 },
        { 0.0, map->cell_size },
        { 0.0, - map->cell_size },
    };

    for (unsigned int i = 0; i < 4; i++) {
        check = crpt_vec2_add(pos, neighbors[i]);
        if (crpt_map_is_solid(map, check))
            normal = crpt_vec2_add(normal, neighbors[i]);
    }
    if (normal.x == 0.0 && normal.y == 0.0)
        return (vec2_t){ 0.0, 0.0 };
    crpt_vec2_scale(normal, -1.0);
    return crpt_vec2_normalized(normal);
}

static vec2_t compute_collision_vector(vec2_t offset, vec2_t pos,
    scene_t *scene)
{
    vec2_t normal = get_wall_normal(scene->map, pos);

    normal = crpt_vec2_scale(normal, crpt_vec2_dot(offset, normal));
    return crpt_vec2_sub(offset, normal);
}

static void apply_sprint(vec2_t *offset)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        *offset = crpt_vec2_scale(*offset, 4.0);
        crpt_camera_interpolate_fov(M_PI_2 - 0.15, 0.0075);
    } else {
        crpt_camera_interpolate_fov(M_PI_2 - 0.225, -0.0075);
    }
}

/*
** Updates the level's scene.
** Nothing much to add there, is there?..
*/
void update_level_scene(scene_t *scene, time_micro_t dt)
{
    double mv_input = get_input_diff(sfKeyUp, sfKeyDown);
    double rotation = get_input_diff(sfKeyRight, sfKeyLeft) * 0.01f;
    vec2_t offset = compute_pos_offset(mv_input);
    vec2_t *pos = crpt_camera_get_position();

    (void)dt;
    crpt_camera_rotate(rotation);
    if (will_collide(scene->map, *pos, offset)) {
        offset = compute_collision_vector(offset, *pos, scene);
    }
    apply_sprint(&offset);
    *pos = crpt_vec2_add(*pos, offset);
}
