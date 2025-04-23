/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_fetch_texture
*/

#include <carpet/assets.h>
#include <carpet/errno.h>


/*
** Fetches a pointer to the texture associated
** to the given id.
** If the given id isn't associated to any texture,
** NULL is returned and CRPT_ERRNO is set.
*/
texture_t *crpt_fetch_texture(const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();
    texture_t *texture = crpt_hashtable_get(&manager->textures, id);

    if (texture == NULL)
        crpt_errno_set(CE_AM_INVALID_ID);
    return texture;
}
