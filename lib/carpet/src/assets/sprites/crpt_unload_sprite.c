/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_unload_sprite
*/

#include <carpet/assets.h>


/*
** Unloads a sprite, removing it from the
** asset manager and freeing the resources
** it has taken.
** This does nothing if the given id isn't
** associated to any sprite.
*/
void crpt_unload_sprite(const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();

    crpt_hashtable_unset(&manager->sprites, id, (free_fnc_t)sfSprite_destroy);
}
