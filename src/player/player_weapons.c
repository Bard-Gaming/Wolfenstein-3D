/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Weapon lookup table
*/

#include <wolf/player.h>


const weapon_t weapon_lookup[WT_COUNT] = {
    { .damage = 5.1, .cooldown = 1.0, .asset_id = "player_pistol" },
    { .damage = 2.6, .cooldown = 0.125, .asset_id = "player_pistol" },
    { .damage = 12.6, .cooldown = 2.0, .asset_id = "player_pistol" },
};
