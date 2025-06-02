#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm
 * @listint_t: double pointer to the head of the list
 *
 * Description: Swap the nodes themselves. Do not modify the
 * integer n of a node.
 * Author: Gamachu
 * Place: et
 */
void insertion_sort_list(listint_t **list)
{
  listint_t *current, *prev, *next;

  if (!list || !*list || !(*list)->next)
    return;

  current = (*list)->next;
  while (current)
  {
    next = current->next;
    while (current->prev && current->n < current->prev->n)
    {
      prev = current->prev;
      
      /* Detach current */
      prev->next = current->next;
      if (current->next)
        current->next->prev = prev;

      /* Insert current before prev */
      current->prev = prev->prev;
      current->next = prev;

      if (prev->prev)
        prev->prev->next = current;
      else
        *list = current;

      prev->prev = current;
      print_list(*list);
    }
    current = next;
  }
}
