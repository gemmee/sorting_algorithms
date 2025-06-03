#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *current, *next;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	while (swapped)
	{
		swapped = 0;

		/* Forward pass */
		current = start;
		while (current->next != end)
		{
			next = current->next;
			if (current->n > next->n)
			{
				/* Swap current and next */
				if (current->prev)
					current->prev->next = next;
				else
					*list = next;

				if (next->next)
					next->next->prev = current;

				current->next = next->next;
				next->prev = current->prev;

				next->next = current;
				current->prev = next;

				swapped = 1;
				print_list(*list);
				/* Stay on the swapped node */
				current = next;
			}
			current = current->next;
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;

		/* Backward pass */
		current = end->prev;
		while (current && current->prev != NULL)
		{
			next = current->prev;
			if (current->n < next->n)
			{
				/* Swap next and current */
				if (next->prev)
					next->prev->next = current;
				else
					*list = current;

				if (current->next)
					current->next->prev = next;

				next->next = current->next;
				current->prev = next->prev;

				current->next = next;
				next->prev = current;

				swapped = 1;
				print_list(*list);
				/* Stay on the swapped node */
				current = next;
			}
			current = current->prev;
		}
		start = current ? current->next : *list;
	}
}

