/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_level_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>
#include <wolf/enemy.h>


static void load_textures(void)
{
    crpt_load_texture(SOLDIER_ASSET("idle_front"), "soldier_idle_front");
    crpt_load_texture("assets/textures/rocks.png", "rocks");
    crpt_load_texture("assets/textures/blue_wall.png", "blue_wall");
    crpt_load_texture("assets/textures/stone_wall.png", "stone_wall");
    crpt_load_texture("assets/textures/brick_wall.png", "brick_wall");
    crpt_load_texture("assets/textures/plank_wall.png", "plank_wall");
    crpt_load_texture("assets/textures/mossy_stone_wall.png",
        "mossy_stone_wall");
}

static void load_enemies(map_t *map)
{
    crpt_map_add_object(map, (void *)create_soldier((vec2_t){ 200.0, 100.0 }));
    crpt_map_add_object(map, (void *)create_soldier((vec2_t){ 342.0, 513.0 }));
    crpt_map_add_object(map, (void *)create_soldier((vec2_t){ 720.0, 78.0 }));
    crpt_map_add_object(map, (void *)create_soldier((vec2_t){ 563.0, 391.0 }));
}

static void place_player(void)
{
    player_t *player = get_player();

    player->pos->x = 4512.0;
    player->pos->y = 4256.0;
    crpt_camera_set_rotation(M_PI_2);
}

/*
** Level's scene load function.
*/
void load_level_scene(scene_t *scene)
{
    load_textures();
    load_player_assets();
    crpt_camera_set_fov(M_PI_2 - 0.225);
    scene->map = crpt_map_import("maps/level_1.mdsc");
    scene->map->floor = (color_t){ 112, 112, 112, 255 };
    scene->map->ceiling = (color_t){ 56, 56, 56, 255 };
    load_enemies(scene->map);
    init_player();
    place_player();
}
