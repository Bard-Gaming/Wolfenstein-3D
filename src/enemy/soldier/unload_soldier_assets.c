/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_soldier_assets
*/

#include <wolf/enemy.h>


/*
** Unloads the idle textures
** of the soldier.
*/
static void unload_idle_textures(void)
{
    crpt_unload_texture("soldier_idle_back");
    crpt_unload_texture("soldier_idle_back_left");
    crpt_unload_texture("soldier_idle_back_right");
    crpt_unload_texture("soldier_idle_front");
    crpt_unload_texture("soldier_idle_front_left");
    crpt_unload_texture("soldier_idle_front_right");
    crpt_unload_texture("soldier_idle_left");
    crpt_unload_texture("soldier_idle_right");
}

/*
** Unloads the move textures
** of the soldier.
*/
static void unload_move_textures(void)
{

    crpt_unload_texture("soldier_move_back");
    crpt_unload_texture("soldier_move_back_left");
    crpt_unload_texture("soldier_move_back_right");
    crpt_unload_texture("soldier_move_front");
    crpt_unload_texture("soldier_move_front_left");
    crpt_unload_texture("soldier_move_front_right");
    crpt_unload_texture("soldier_move_left");
    crpt_unload_texture("soldier_move_right");
}

/*
** Unloads the assets that are loaded
** by load_soldier_assets()
*/
void unload_soldier_assets(void)
{
    unload_idle_textures();
    unload_move_textures();
    crpt_unload_texture("soldier_shoot");
    crpt_unload_texture("soldier_die");
}
