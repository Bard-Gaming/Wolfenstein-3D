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
    crpt_load_texture("assets/textures/rocks.png", "rocks");
    crpt_load_texture("assets/textures/blue_wall.png", "blue_wall");
    crpt_load_texture("assets/textures/stone_wall.png", "stone_wall");
    crpt_load_texture("assets/textures/brick_wall.png", "brick_wall");
    crpt_load_texture("assets/textures/plank_wall.png", "plank_wall");
    crpt_load_texture("assets/textures/mossy_stone_wall.png",
        "mossy_stone_wall");
}

static void place_enemies(map_t *map)
{
    crpt_map_add_object(map, (void *)create_soldier(4628.0, 3786.0));
    crpt_map_add_object(map, (void *)create_soldier(4863.5, 4188.5));
    crpt_map_add_object(map, (void *)create_soldier(2397.0, 3370.0));
    crpt_map_add_object(map, (void *)create_soldier(3686.0, 4831.0));
    crpt_map_add_object(map, (void *)create_soldier(3694.0, 5403.0));
    crpt_map_add_object(map, (void *)create_soldier(3544.0, 5337.0));
    crpt_map_add_object(map, (void *)create_soldier(1767.0, 3400.0));
    crpt_map_add_object(map, (void *)create_soldier(307.0, 3985.0));
}

static void place_player(void)
{
    player_t *player = get_player();

    player->pos->x = 4512.0;
    player->pos->y = 3296.0;
    crpt_camera_set_rotation(3 * M_PI_2);
}

/*
** Level's scene load function.
*/
void load_level_scene(scene_t *scene)
{
    load_textures();
    load_player_assets();
    load_soldier_assets();
    scene->map = crpt_map_import("maps/level_1.mdsc");
    scene->map->floor = (color_t){ 112, 112, 112, 255 };
    scene->map->ceiling = (color_t){ 56, 56, 56, 255 };
    place_enemies(scene->map);
    crpt_camera_set_fov(M_PI_2 - 0.225);
    init_player();
    place_player();
}
