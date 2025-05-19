/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_raycast
*/

#include <carpet/ray.h>
#include <carpet/map.h>


/*
** Casts a vertical ray and returns the ray
** of where the first vertical wall was hit.
** If no wall was hit, a ray with infinite
** distance is returned instead.
*/
static ray_t cast_ray_vert(vec2_t origin, double angle, const map_t *map)
{
    const float tangent = tan(angle);
    bool is_right = cos(angle) > 0.0;
    ray_t ray = { RS_VERTICAL, 0.0, 0.0, { 0 } };
    vec2_t offset = is_right ?
        (vec2_t){ map->cube_size, - map->cube_size * tangent } :
        (vec2_t){ - map->cube_size, map->cube_size * tangent };

    ray.pos.x = ((int)(origin.x / map->cube_size) * map->cube_size) +
        (is_right ? map->cube_size : -0.0001);
    ray.pos.y = (origin.x - ray.pos.x) * tangent + origin.y;
    for (unsigned int dof = 0; dof < 50; dof++) {
        if (crpt_map_is_solid(map, ray.pos))
            return ray;
        ray.pos = crpt_vec2_add(ray.pos, offset);
    }
    return (ray_t){ RS_VERTICAL, 0.0, 1.0 / 0.0, origin };
}

/*
** Casts a horizontal ray and returns the ray
** of where the first horizontal wall was hit.
** If no wall was hit, a ray with infinite
** distance is returned instead.
*/
static ray_t cast_ray_horiz(vec2_t origin, double angle, const map_t *map)
{
    const float tangent = 1.0 / tan(angle);
    ray_t ray = { RS_HORIZONTAL, 0.0, 0.0, { 0 } };
    bool is_top = sin(angle) > 0.0;
    vec2_t offset = is_top ?
        (vec2_t){ map->cube_size * tangent, - map->cube_size } :
        (vec2_t){ - map->cube_size * tangent, map->cube_size };

    ray.pos.y = ((int)(origin.y / map->cube_size) * map->cube_size) +
        (is_top ? -0.0001 : map->cube_size);
    ray.pos.x = (origin.y - ray.pos.y) * tangent + origin.x;
    for (unsigned int dof = 0; dof < 50; dof++) {
        if (crpt_map_is_solid(map, ray.pos))
            return ray;
        ray.pos = crpt_vec2_add(ray.pos, offset);
    }
    return (ray_t){ RS_HORIZONTAL, 0.0, 1.0 / 0.0, origin };
}

/*
** Updates the given ray's distance field
** (i.e. z coordinate) with its distance to
** the given point of origin.
*/
static void update_distance(ray_t *ray, vec2_t origin, double rotation)
{
    ray->dist =
        cos(rotation) * (ray->pos.x - origin.x) -
        sin(rotation) * (ray->pos.y - origin.y);
}

/*
** Returns a 3D vector that describes the
** wall that was hit.
** The vector is in the following format:
** { pos x, pos y, dist }.
**
** If no wall was hit, this returns a vector
** of coordinates { 0, 0, inf }.
*/
ray_t crpt_raycast(vec2_t origin, double rotation, const map_t *map)
{
    ray_t vertical_ray = cast_ray_vert(origin, rotation, map);
    ray_t horizontal_ray = cast_ray_horiz(origin, rotation, map);
    ray_t *closest;

    if (!isinff(vertical_ray.dist))
        update_distance(&vertical_ray, origin, rotation);
    if (!isinff(horizontal_ray.dist))
        update_distance(&horizontal_ray, origin, rotation);
    closest = vertical_ray.dist < horizontal_ray.dist ?
        &vertical_ray : &horizontal_ray;
    closest->angle = rotation;
    return *closest;
}
