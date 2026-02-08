#include "sort.h"

/**
 * swap_prev - swap a node with its previous node in a doubly linked list
 * @list: pointer to the head pointer of the list
 * @node: pointer to the node to move left
 *
 * Return: new position of node (after swap)
 */
static listint_t *swap_prev(listint_t **list, listint_t *node)
{
	listint_t *prev;

	prev = node->prev;

	/* detach node from its current position (connect prev <-> node->next) */
	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;

	/* move node before prev */
	node->prev = prev->prev;
	node->next = prev;

	prev->prev = node;
	if (node->prev)
		node->prev->next = node;
	else
		*list = node; /* node is new head */

	return (node);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: pointer to the head pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	while (cur)
	{
		next = cur->next;

		while (cur->prev && cur->n < cur->prev->n)
		{
			cur = swap_prev(list, cur);
			print_list(*list);
		}

		cur = next;
	}
}
