/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_load_texture
*/

#include <carpet/assets.h>
#include <carpet/memory.h>
#include <stdlib.h>


static void *load_texture(const char *path)
{
    return sfTexture_createFromFile(path, NULL);
}

/*
** Loads a given texture into the asset
** manager and associates it to the given id.
*/
void crpt_load_texture(const char *path, const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();

    return crpt_asset_manager_load(
        &manager->textures, path,
        id, load_texture
    );
}
