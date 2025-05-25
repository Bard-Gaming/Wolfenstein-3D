/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** unload_soldier_assets
*/

#include <wolf/enemy.h>


/*
** Unloads the assets that are loaded
** by load_soldier_assets()
*/
void unload_soldier_assets(void)
{
    crpt_unload_texture("soldier_idle_front");
    crpt_unload_texture("soldier_die");
}
