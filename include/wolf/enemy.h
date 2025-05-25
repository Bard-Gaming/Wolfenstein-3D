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
    #define SOLDIER_HURT_TIME 500  // in fixed update cycles


typedef enum {
    OT_DECORATION,
    OT_ENEMY,
    OT_DEAD_ENEMY,  // separate to avoid hitscans reaching dead enemies
} object_type_t;


typedef enum {
    ET_UNSET,

    ET_SOLDIER,
} enemy_type_t;


typedef enum {
    ES_IDLE,
    ES_MOVE,
    ES_ATTACK,
    ES_DEAD,
} enemy_state_t;


/*
** This struct inherits from
** carpet's object struct, hence
** the first field.
*/
typedef struct {
    object_t object;  // /!\ keep first /!|
    enemy_type_t type;

    // State:
    enemy_state_t state;
    unsigned int state_time;  // cycles passed in current state

    double rotation;

    // Health:
    double health;
    double max_health;
    unsigned int hurt_time;

    // Animation
    int frame;             // current frame index
    int frame_time;        // how many ticks this frame has shown
} enemy_t;


// Base enemy functions:
enemy_t *create_enemy(const texture_t *texture, vec2_t pos);
void set_enemy_max_health(enemy_t *enemy, double health);
void hurt_enemy(enemy_t *enemy, double damage);
void kill_enemy(enemy_t *enemy);

// Soldier functions:
enemy_t *create_soldier(double x, double y);
void hurt_soldier(enemy_t *soldier, double damage);
void kill_soldier(enemy_t *soldier);
void load_soldier_assets(void);
void unload_soldier_assets(void);
void update_soldier(enemy_t *soldier);
void update_soldier_texture(enemy_t *soldier);
void set_soldier_state(enemy_t *soldier, enemy_state_t state);


#endif
