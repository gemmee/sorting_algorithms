#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the insertion sort algorithm with a single-swap approach
 * @list: Double pointer to the head of the list
 * Author: Gamachu
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *search, *insert_before;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		search = current->prev;
		insert_before = current;
		/* Search backward for the insertion point */
		while (search && current->n < search->n)
		{
			insert_before = search;
			search = search->prev;
		}

		/* Only move if we found a new position */
		if (insert_before != current)
		{
			/* Detach current */
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			/* Insert current before insert_before */
			current->prev = insert_before->prev;
			current->next = insert_before;
			insert_before->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current; /* Update head if necessary */

			print_list(*list);
		}
		current = current->next;
	}
}

