#include "lists.h"

int check_cycle(listint_t *list) {
  listint_t *slow = list;
  listint_t *fast = list;

  while (fast){
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow){
      return (1);
    }
  }
  return (0);
}
