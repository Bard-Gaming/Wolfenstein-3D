/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_fetch_font
*/

#include <carpet/assets.h>
#include <carpet/errno.h>


/*
** Fetches a pointer to the font associated
** to the given id.
** If the given id isn't associated to any texture,
** NULL is returned and CRPT_ERRNO is set.
*/
font_t *crpt_fetch_font(const char *id)
{
    asset_manager_t *manager = crpt_asset_manager_get();
    font_t *font = crpt_hashtable_get(&manager->fonts, id);

    if (font == NULL)
        crpt_errno_set(CE_AM_INVALID_ID);
    return font;
}
