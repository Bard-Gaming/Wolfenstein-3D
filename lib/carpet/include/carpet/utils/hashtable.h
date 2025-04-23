/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Header file for carpet lib's
** hashtables
*/

#ifndef LIB_CARPET_UTILS_HASHTABLE_H
    #define LIB_CARPET_UTILS_HASHTABLE_H
    #include <carpet/types.h>

    #define CRPT_HASH_INIT_CAP 50
    #define CRPT_HASH_LF 0.7f  // load factor


struct _ht_bucket {
    char *key;
    void *data;
    struct _ht_bucket *next;
};


struct carpet_hashtable {
    struct _ht_bucket **buckets;
    size_t capacity;
    size_t count;
};


// User functions:
void crpt_hashtable_set(crpt_hashtable_t *table, const char *key, void *data);
void *crpt_hashtable_get(const crpt_hashtable_t *table, const char *key);
void crpt_hashtable_delete(crpt_hashtable_t *table, free_fnc_t free_data);

// Internal functions:
size_t crpt_hash(const char *key, size_t max);


#endif
