#include "sort.h"
#include <stdio.h>

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
  listint_t *temp1, *temp2, *temp3;
  int flag;

  temp1 = temp2 = temp3 = *list;
  while (temp3->next)
  {
    temp3 = temp3->next;
    temp1 = temp3;
    temp2 = temp1;
    flag = 0;
    while (temp2->prev && temp1->n < temp2->prev->n)
    {
      temp2 = temp2->prev;
      flag = 1;
    }
    if (flag)
    {
      temp1->prev->next = temp1->next;
      temp1->next->prev = temp1->prev;
      temp1->next = temp2;
      temp1->prev = temp2->prev;
      temp2->prev = temp1;
      print_list(*list);
      print_list(temp1);
    }
  }
}
