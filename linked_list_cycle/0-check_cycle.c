#include "lists.h"

/**
 * check_cycle - Checks if a linked list has a cycle.
 *
 * This function checks whether a given linked list has a cycle by using
 * Floyd's Cycle Detection Algorithm.
 *
 * @list: A pointer to the head of the linked list.
 *
 * Return: 1 if a cycle is detected, 0 otherwise.
 */
int check_cycle(listint_t *list) {
  listint_t *slow = list;
  listint_t *fast = list;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow) {
      return (1);
    }
  }
  return (0);
}
