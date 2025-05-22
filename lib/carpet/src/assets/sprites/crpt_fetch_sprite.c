/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_fetch_sprite
*/

#include <carpet/assets.h>
#include <carpet/errno.h>


/*
** Fetches the sprite associated to the given
** ID. If the given ID isn't associated to any
** sprite, CRPT_ERRNO is set an NULL is returned.
*/
sprite_t *crpt_fetch_sprite(const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();
    sprite_t *sprite = crpt_hashtable_get(&manager->sprites, id);

    if (sprite == NULL)
        crpt_errno_set(CE_AM_INVALID_ID);
    return sprite;
}
