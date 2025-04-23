/*
** EPITECH PROJECT, 2025
** Project - Carpet Lib
** File description:
** Implementation for
** crpt_hashtable_delete
*/

#include <carpet/utils/hashtable.h>
#include <string.h>
#include <stdlib.h>


/*
** Recursively deletes the data
** associated to each bucket in the
** linked list.
*/
static void delete_buckets(struct _ht_bucket *head, free_fnc_t free_data)
{
    if (head == NULL)
        return;
    delete_buckets(head->next, free_data);
    free(head->key);
    if (free_data)
        free_data(head->data);
    free(head);
}

/*
** Delete the contents of the hashtable
** and reset it to its initial state
** (i.e. null-initialized).
** If the given free_data function, the
** stored data will be left unchanged.
*/
void crpt_hashtable_delete(crpt_hashtable_t *table, free_fnc_t free_data)
{
    for (size_t i = 0; i < table->capacity; i++)
        delete_buckets(table->buckets[i], free_data);
    free(table->buckets);
    memset(table, 0, sizeof(crpt_hashtable_t));
}
