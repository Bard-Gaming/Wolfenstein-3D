/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_soldier_assets
*/

#include <wolf/enemy.h>


/*
** Loads the idle textures
** of the soldier.
*/
static void load_idle_textures(void)
{
    crpt_load_texture(SOLDIER_ASSET("idle_back"), "soldier_idle_back");
    crpt_load_texture(SOLDIER_ASSET("idle_back_left"),
        "soldier_idle_back_left");
    crpt_load_texture(SOLDIER_ASSET("idle_back_right"),
        "soldier_idle_back_right");
    crpt_load_texture(SOLDIER_ASSET("idle_front"), "soldier_idle_front");
    crpt_load_texture(SOLDIER_ASSET("idle_front_left"),
        "soldier_idle_front_left");
    crpt_load_texture(SOLDIER_ASSET("idle_front_right"),
        "soldier_idle_front_right");
    crpt_load_texture(SOLDIER_ASSET("idle_left"), "soldier_idle_left");
    crpt_load_texture(SOLDIER_ASSET("idle_right"), "soldier_idle_right");
}

/*
** Loads the move textures
** of the soldier.
*/
static void load_move_textures(void)
{
    crpt_load_texture(SOLDIER_ASSET("move_back"), "soldier_move_back");
    crpt_load_texture(SOLDIER_ASSET("move_back_left"),
        "soldier_move_back_left");
    crpt_load_texture(SOLDIER_ASSET("move_back_right"),
        "soldier_move_back_right");
    crpt_load_texture(SOLDIER_ASSET("move_front"), "soldier_move_front");
    crpt_load_texture(SOLDIER_ASSET("move_front_left"),
        "soldier_move_front_left");
    crpt_load_texture(SOLDIER_ASSET("move_front_right"),
        "soldier_move_front_right");
    crpt_load_texture(SOLDIER_ASSET("move_left"), "soldier_move_left");
    crpt_load_texture(SOLDIER_ASSET("move_right"), "soldier_move_right");
}

/*
** Loads the assets that are needed
** when using soldiers.
*/
void load_soldier_assets(void)
{
    load_idle_textures();
    load_move_textures();
    crpt_load_texture(SOLDIER_ASSET("shoot"), "soldier_shoot");
    crpt_load_texture(SOLDIER_ASSET("die"), "soldier_die");
}
