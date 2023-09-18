#include "lists.h"

/**
 * get_node_at_index - gets a node at a specific index in the linked list
 * @head: pointer to head of list
 * @index: index of the node to get
 * Return: pointer to the node, or NULL if the node doesn't exist
 */

listint_t *get_node_at_index(listint_t *head, unsigned int index)
{
  unsigned int count = 0;
  while (head)
  {
    if (count == index)
          return (head);
    count++;
    head = head->next;
  }
  return (NULL);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head node
 * Return: 1 if it's a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *temp = *head;
    unsigned int length = 0, i;

    if(!head) return (1);

    while(temp){
      temp = temp -> next;
      length++;
    }

    for (i = 0; i < length; i++){
      listint_t *start = get_node_at_index(*head, i);
      listint_t *end = get_node_at_index(*head, length - i - 1);
      if (start->n != end->n) return (0);
    }
    return (1);
}
