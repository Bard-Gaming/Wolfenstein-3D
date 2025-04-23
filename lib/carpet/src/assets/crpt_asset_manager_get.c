/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_asset_manager_get
*/

#include <carpet/assets.h>


/*
** Retrieves a pointer to the library's
** asset manager.
*/
asset_manager_t *crpt_asset_manager_get(void)
{
    static asset_manager_t manager = { 0 };

    return &manager;
}
