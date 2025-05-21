/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_hashtable_unset
*/

#include <carpet/utils/hashtable.h>
#include <string.h>
#include <stdlib.h>


/*
** Deletes the given head bucket,
** and all of its contained data.
*/
static void delete_element(struct _ht_bucket *head,
    struct _ht_bucket **bucket_start, struct _ht_bucket *prev, free_fnc_t rm)
{
    if (prev == NULL)
        *bucket_start = head->next;
    else
        prev->next = head->next;
    if (rm != NULL)
        rm(head->data);
    free(head->key);
    free(head);
}

/*
** Unsets the value stored with the given key.
** If the key isn't associated with anything in
** the hashtable, this function does nothing.
** If the given free function is NULL, the data
** stored within the bucket won't be freed.
*/
void crpt_hashtable_unset(crpt_hashtable_t *table, const char *key,
    free_fnc_t free)
{
    struct _ht_bucket *prev = NULL;
    struct _ht_bucket *head;
    size_t index;

    if (table->capacity == 0)
        return;
    index = crpt_hash(key, table->capacity);
    head = table->buckets[index];
    while (head != NULL) {
        if (strcmp(head->key, key) == 0)
            return delete_element(head, table->buckets + index, prev, free);
        prev = head;
        head = head->next;
    }
    return;
}
