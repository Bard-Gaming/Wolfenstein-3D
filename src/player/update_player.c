/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** update_player
*/

#include <wolf/player.h>
#include <wolf/settings.h>


/*
** Updates the movement based on the
** camera's rotation and the given intensity.
*/
static vec2_t compute_pos_offset(double intensity)
{
    double rotation = crpt_camera_get_rotation();

    return (vec2_t){
        .x = cos(rotation) * intensity,
        .y = - sin(rotation) * intensity,
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
    const map_t *map)
{
    vec2_t normal = get_wall_normal(map, pos);

    normal = crpt_vec2_scale(normal, crpt_vec2_dot(offset, normal));
    return crpt_vec2_sub(offset, normal);
}

static void apply_sprint(vec2_t *offset)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        *offset = crpt_vec2_scale(*offset, 4.0);
        crpt_camera_interpolate_fov(PLAYER_SPRINT_FOV, 0.0075);
    } else {
        crpt_camera_interpolate_fov(PLAYER_FOV, -0.0075);
    }
}

static bool should_shoot(player_t *player)
{
    return
        is_key_pressed(CK_SHOOT) &&
        (!player->holding_fire || weapon_lookup[player->weapon].autofire);
}

/*
** Updates the level's scene.
** Nothing much to add there, is there?..
*/
void update_player(const map_t *map, time_micro_t dt)
{
    player_t *player = get_player();
    vec2_t input_vec = get_input_vec(dt);
    vec2_t offset = compute_pos_offset(input_vec.x);

    if (!is_key_pressed(CK_SHOOT))
        player->holding_fire = false;
    crpt_camera_rotate(input_vec.y);
    if (will_collide(map, *player->pos, offset))
        offset = compute_collision_vector(offset, *player->pos, map);
    apply_sprint(&offset);
    *player->pos = crpt_vec2_add(*player->pos, offset);
    player->shoot_delay = fmax(player->shoot_delay - dt / 1000000.0, 0.0);
    player->hurt_time = fmax(player->hurt_time - dt / 5000000.0, 0.0);
    if (should_shoot(player))
        player_use_weapon();
    if (is_key_pressed(CK_SHOOT))
        player->holding_fire = true;
}
