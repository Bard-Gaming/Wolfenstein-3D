/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_hashtable_set
*/

#include <carpet/utils/hashtable.h>
#include <carpet/memory.h>
#include <string.h>
#include <stdlib.h>


/*
** Retrieves the bucket that
** matches the given key.
*/
static void *retrieve_bucket(const char *key, void *head)
{
    struct _ht_bucket *current = head;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

/*
** Grows the given hash table, increasing its
** total capacity and rehashing all its values.
*/
static void grow_table(crpt_hashtable_t *table)
{
    size_t new_capacity = table->capacity * 2 ?: CRPT_HASH_INIT_CAP;
    struct _ht_bucket **new_data = ccalloc(new_capacity, sizeof(void *));
    struct _ht_bucket *head;
    struct _ht_bucket *next;
    size_t index;

    for (size_t i = 0; i < table->capacity; i++) {
        head = table->buckets[i];
        while (head != NULL) {
            index = crpt_hash(head->key, new_capacity);
            next = head->next;
            head->next = new_data[index];
            new_data[index] = head;
            head = next;
        }
    }
    free(table->buckets);
    table->buckets = new_data;
    table->capacity = new_capacity;
}

/*
** Updates the hash table to associate
** the given key to the given data, irregardless
** of what was previously associated with the given
** key (if anything was stored at all).
*/
void crpt_hashtable_set(crpt_hashtable_t *table, const char *key, void *data)
{
    struct _ht_bucket *data_bucket;
    size_t index;

    if (table->count == CRPT_HASH_LF * table->capacity)
        grow_table(table);
    index = crpt_hash(key, table->capacity);
    data_bucket = retrieve_bucket(key, table->buckets[index]);
    if (data_bucket != NULL) {
        data_bucket->data = data;
        return;
    }
    data_bucket = cmalloc(sizeof(struct _ht_bucket));
    data_bucket->key = strdup(key);
    data_bucket->data = data;
    data_bucket->next = table->buckets[index];
    table->buckets[index] = data_bucket;
    table->count++;
}
