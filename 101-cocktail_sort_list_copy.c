#include "sort.h"

/**
 * swap_adjacent - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @current: Double pointer to the current node (will update it after swap)
 * @dir: Direction of traversal (FORWARD or BACKWARD)
 */
void swap_adjacent(listint_t **list, listint_t **current, direction_t dir)
{
	listint_t *node1, *node2;

	if (!list || !current || !*current)
		return;

	if (dir == FORWARD)
	{
		node1 = *current;
		node2 = node1->next;
	}
	else
	{
		node2 = *current;
		node1 = node2->prev;
	}

	if (!node1 || !node2 || node1->next != node2)
		return;

	/* Relink node1->prev to node2 */
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;

	print_list(*list);
}


/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 *
 * Author: Gamachu
 * Place: Mariyam, Jun 03, 2025
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *current;
	direction_t dir = FORWARD;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	while (swapped)
	{
		swapped = 0;

		if (dir == FORWARD)
		{
			current = start;
			while (current->next != end)
			{
				if (current->n > current->next->n)
				{
					swap_adjacent(list, &current, FORWARD);
					swapped = 1;
				}
				else
				{
					current = current->next;				}
			}
			end = current;
      			if (!swapped)
        			break;
			dir = BACKWARD;
		}
		else
		{
			current = end->prev;
			while (current && current->prev != NULL && current->prev != start->prev)
			{
				if (current->n < current->prev->n)
				{
					swap_adjacent(list, &current, BACKWARD);
					swapped = 1;
				}
				else
				{
					current = current->prev;
				}
			}
			if (!swapped)
			    break;
			start = current ? current->next : *list;
			dir = FORWARD;
		}
	}
}

