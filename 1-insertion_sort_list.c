#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 *
 * @node1: Tthe first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - funct sorts a doubly linked list of int in asc order
 * @list: A pointer to the head of a doubly-linked list
 *
 * Description: Prints the list after sorting.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *insert = current->prev;
		listint_t *tmp = current;

		while (insert != NULL && tmp->n < insert->n)
		{
			swap_nodes(list, &insert, tmp);
			print_list((const listint_t *)*list);
			tmp = insert;
			insert = insert->prev;
		}

		current = current->next;
	}
}
