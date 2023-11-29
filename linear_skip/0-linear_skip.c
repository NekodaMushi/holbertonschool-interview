#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list.
 * @value: the value to search for.
 * 
 * Return: pointer to the first node where the value is located, or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *node = list, *express = NULL;

    if (list == NULL)
        return NULL;

    while (node) {
        express = node->express;
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);


        if (!express || express->n >= value)
            break;

        node = express;
    }

    if (!express)
        while (node->next)
            node = node->next;

    printf("Value found between indexes [%lu] and [%lu]\n", 
           express ? express->index : node->index, node->index);

    // Linear search
    while (list != express) {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        if (list->n == value)
            return list;
        list = list->next;
    }

    return NULL;
}
