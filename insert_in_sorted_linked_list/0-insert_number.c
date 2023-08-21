#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - fct that inserts a number into a sorted singly linked list.
 * @head - head of the list
 * @number - number insered
 * Return: the address of the new node, or NULL if it failed
*/

listint_t *insert_node(listint_t **head, int number) {

    listint_t *new, *tmp;

    new = malloc(sizeof(listint_t));
    if (new == NULL){
      return(NULL);
    }

    /* Create the unlinked node, yet*/
    new->n = number;
    new->next = NULL;

    if (*head == NULL) {
      *head = new;
      return (new);
    }

    /* Navigate the linked list*/
    tmp = *head;
    if (*head != NULL) {
      while (tmp-> next && tmp->next->n < number){
        tmp = tmp-> next;
      }
    }

    /* Insert the node*/
      new->next = tmp->next;
      tmp->next = new;

    return (new);
}
