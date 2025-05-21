/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_unload_texture
*/

#include <carpet/assets.h>


/*
** Unloads the texture associated to the
** given id. If no texture is associated to id,
** this does nothing.
*/
void crpt_unload_texture(const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();

    crpt_hashtable_unset(
        &manager->textures,
        id,
        (free_fnc_t)sfTexture_destroy
    );
}
