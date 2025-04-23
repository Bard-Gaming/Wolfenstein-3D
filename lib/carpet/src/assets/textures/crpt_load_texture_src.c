/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_load_texture_src
*/

#include <carpet/assets.h>
#include <carpet/memory.h>
#include <carpet/errno.h>


/*
** Loads a given texture from a source into the asset
** manager and associates it to the given id.
*/
void crpt_load_texture_src(void *data, size_t len, const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();
    texture_t *texture;

    if (crpt_hashtable_get(&manager->textures, id) != NULL)
        return crpt_errno_set(CE_AM_REUSED_ID);
    texture = sfTexture_createFromMemory(data, len, NULL);
    if (texture == NULL)
        return crpt_errno_set(CE_AM_LOAD_FAIL);
    crpt_hashtable_set(&manager->textures, id, texture);
}
