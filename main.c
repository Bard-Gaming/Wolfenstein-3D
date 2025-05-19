/*
** EPITECH PROJECT, 2024
** Project - Wolf 3D
** File description:
** Program Entry
*/

#include <carpet.h>


static void load_custom_scene(scene_t *scene)
{
    object_t border = { .type = OT_WALL, .color = sfWhite };
    object_t room = { .type = OT_ROOM, .color = sfWhite };

    crpt_load_texture("assets/textures/bricks.png", "bricks");
    border.texture = crpt_fetch_texture("bricks");
    scene->map = crpt_map_create(50, 50);
    crpt_map_create_border(scene->map, &border);
    crpt_map_randomize(scene->map, 20, &border);
    crpt_map_fill_empty(scene->map, &room);
}

static void unload_custom_scene(scene_t *scene)
{
    crpt_map_delete(scene->map);
    scene->map = NULL;
}

int main(void)
{
    scene_t scene = {
        .load = load_custom_scene,
        .unload = unload_custom_scene,
        .update = crpt_scene_default_update,
    };

    crpt_game_init();
    crpt_scene_set(&scene);
    crpt_game_mainloop();
    crpt_game_term();
}
