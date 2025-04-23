/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_hash
*/

#include <carpet/utils/hashtable.h>


/*
** Carpet's hash function.
** This function hashes the given key into
** a value in the range of [0; max[
*/
size_t crpt_hash(const char *key, size_t max)
{
    size_t result = 0;

    for (size_t i = 0; key[i] != '\0'; i++)
        result += key[i] * i * 13 + 4;
    return result % max;
}
