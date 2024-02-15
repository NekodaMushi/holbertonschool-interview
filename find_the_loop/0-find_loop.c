#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: A pointer to the head of the linked list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow, *fast;

    slow = head;
    fast = slow;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow && fast)
            {
                if (slow == fast)
                    return (slow);
                slow = slow->next;
                fast = fast->next;
            }
        }
    }
    return (NULL);
}
