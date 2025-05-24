/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Weapon lookup table
*/

#include <wolf/player.h>


const weapon_t weapon_lookup[WT_COUNT] = {
    { .damage = 2.5, .cooldown = 1.0, .asset_id = "player_pistol" },
};
