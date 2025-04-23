/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_hashtable_get
*/

#include <carpet/utils/hashtable.h>
#include <string.h>


/*
** Retrieves the value associated to the
** given key within the hashtable.
** Returns NULL if the key isn't associated
** to any data.
*/
void *crpt_hashtable_get(const crpt_hashtable_t *table, const char *key)
{
    struct _ht_bucket *head;
    size_t index;

    if (table->capacity == 0)
        return NULL;
    index = crpt_hash(key, table->capacity);
    head = table->buckets[index];
    while (head != NULL) {
        if (strcmp(head->key, key) == 0)
            return head->data;
        head = head->next;
    }
    return NULL;
}
