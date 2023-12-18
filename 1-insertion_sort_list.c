#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: A pointer to the head of the doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	/* Check for edge cases: empty list or a list with a single element */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Initialize the current pointer to the second element in the list */
	current = (*list)->next;

	/* Traverse the list starting from the second element */
	while (current != NULL)
	{
		/* Store the next pointer before potential modifications */
		temp = current->next;
		/* Compare the current element with its previous elements*/
		/* and swap if necessary */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Update the next pointer of the previous element */
			current->prev->next = current->next;
			/* Update the previous pointer of the next element */
			if (current->next != NULL)
				current->next->prev = current->prev;

			/* Perform the swap by updating pointers */
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			/* Update the head of the list if necessary */
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			/* Print the list after each swap (for visualization purposes) */
			print_list(*list);
		}
		/* Move to the next element in the list */
		current = temp;
	}
}
