/*
** EPITECH PROJECT, 2025
** Project - Wolf3D
** File description:
** Header file for the game's
** enemies (base)
*/

#ifndef WOLF_ENEMY_H
    #define WOLF_ENEMY_H
    #include <carpet.h>

    #define SOLDIER_ASSET(file) "assets/sprites/soldier/" file ".png"


typedef enum {
    ES_IDLE,
    ES_MOVE,
    ES_ATTACK,
} enemy_state_t;


/*
** This struct inherits from
** carpet's object struct, hence
** the first field.
*/
typedef struct {
    object_t object;  // /!\ keep first /!|

    // State:
    enemy_state_t state;
    unsigned int state_time;  // cycles passed in current state

    double rotation;

    double health;
    double max_health;
} enemy_t;


// Base enemy functions:
enemy_t *create_enemy(const texture_t *texture, vec2_t pos);
void set_enemy_max_health(enemy_t *enemy, double health);

// Soldier functions:
enemy_t *create_soldier(vec2_t pos);
void update_soldier(enemy_t *soldier);
void update_soldier_texture(enemy_t *soldier);
void set_soldier_state(enemy_t *soldier, enemy_state_t state);


#endif
