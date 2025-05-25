/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Weapon lookup table
*/

#include <wolf/player.h>


const weapon_t weapon_lookup[WT_COUNT] = {
    { .damage = 5.1, .cooldown = 1.0, .autofire = false,
        .asset_id = "player_pistol" },
    { .damage = 2.6, .cooldown = 0.125, .autofire = true,
        .asset_id = "player_submachine" },
    { .damage = 1.0, .cooldown = 0.0625, .autofire = true,
        .asset_id = "player_minigun" },
    { .damage = 12.6, .cooldown = 2.0, .autofire = false,
        .asset_id = "player_pistol" },
};
