/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_level_scene
*/

#include <wolf/scenes.h>


/*
** Level's scene load function.
*/
void load_level_scene(scene_t *scene)
{
    object_t border = { .type = OT_WALL, .color = sfWhite };
    object_t room = { .type = OT_ROOM, .color = sfWhite };

    crpt_load_texture("assets/textures/bricks.png", "bricks");
    border.texture = crpt_fetch_texture("bricks");
    scene->map = crpt_map_create(50, 50);
    scene->map->floor = (color_t){ 100, 100, 100, 255 };
    scene->map->ceiling = (color_t){ 70, 70, 70, 255 };
    crpt_map_create_border(scene->map, &border);
    crpt_map_randomize(scene->map, 20, &border);
    crpt_map_fill_empty(scene->map, &room);
}
