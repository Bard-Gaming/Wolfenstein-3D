/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_level_scene
*/

#include <wolf/scenes.h>
#include <wolf/player.h>


static void load_textures(void)
{
    crpt_load_texture("assets/textures/blue_wall.png", "blue_wall");
    crpt_load_texture("assets/textures/healthbar_full.png", "hb_full");
    crpt_load_texture("assets/textures/healthbar_empty.png", "hb_empty");
}

/*
** Level's scene load function.
*/
void load_level_scene(scene_t *scene)
{
    map_cell_t border = { .type = MCT_WALL, .color = sfWhite };

    load_textures();
    crpt_camera_set_fov(M_PI_2 - 0.225);
    border.texture = crpt_fetch_texture("blue_wall");
    scene->map = crpt_map_create(50, 50);
    scene->map->floor = (color_t){ 112, 112, 112, 255 };
    scene->map->ceiling = (color_t){ 56, 56, 56, 255 };
    crpt_map_create_border(scene->map, &border);
    crpt_map_randomize(scene->map, 20, &border);
    init_player();
}
