/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Implementation for
** load_soldier_assets
*/

#include <wolf/enemy.h>


/*
** Loads the assets that are needed
** when using soldiers.
*/
void load_soldier_assets(void)
{
    crpt_load_texture(SOLDIER_ASSET("idle_front"), "soldier_idle_front");
    crpt_load_texture(SOLDIER_ASSET("die"), "soldier_die");
}
