/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_load_sprite
*/

#include <carpet/assets.h>
#include <carpet/memory.h>
#include <carpet/errno.h>
#include <stdlib.h>


/*
** Loads a sprite into the library's
** asset manager using the given texture.
** The loaded sprite can be fetched later
** using the crpt_fetch_sprite() function.
*/
void crpt_load_sprite(const texture_t *texture, const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();
    sprite_t *sprite;

    if (crpt_hashtable_get(&manager->sprites, id) != NULL)
        return crpt_errno_set(CE_AM_REUSED_ID);
    sprite = sfSprite_create();
    if (sprite == NULL) {
        crpt_errno_set(CE_NO_MEMORY);
        crpt_perror("carpet");
        exit(CRPT_CRITICAL_ERROR);
    }
    sfSprite_setTexture(sprite, texture, true);
    crpt_hashtable_set(&manager->sprites, id, sprite);
}
