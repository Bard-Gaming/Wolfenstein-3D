/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Header file for the game's
** enemies
*/

#ifndef WOLF_ENEMY_H
    #define WOLF_ENEMY_H
    #include <carpet.h>


/*
** This struct inherits from
** carpet's object struct, hence
** the first field.
*/
typedef struct {
    object_t object;  // /!\ keep first /!|

    double health;
    double health_max;
} enemy_t;


#endif
