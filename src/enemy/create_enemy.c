/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** create_enemy
*/

#include <wolf/enemy.h>


/*
** Creates a generic enemy at the
** given position.
*/
enemy_t *create_enemy(const texture_t *texture, vec2_t pos)
{
    enemy_t *enemy = cmalloc(sizeof(enemy_t));

    crpt_object_defaults((void *)enemy);
    crpt_object_set_position((void *)enemy, pos);
    enemy->object.texture = texture;
    enemy->state = ES_IDLE;
    enemy->rotation = 0.0;
    return enemy;
}
