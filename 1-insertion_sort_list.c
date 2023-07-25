#include "sort.h"

/**
 * swap_node = this swaps two nodes in the listint_t
 * @h: is the pointer to the head of the listint_t
 * @n1: pointer to the 1st node to be swapped
 * @n2: 2nd node to be swapped
 */
void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * insertion_sort_list - this sorts a doubly linked list of integers in
			 ascending order using the Insertion sort algorithm.
 * @list: pointer to the head of the doubly linked list of integers
 *
 * Description: it prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *integ, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (integ = (*list)->next; integ != NULL; integ = temp)
	{
		temp = integ->next;
		insert = integ->prev;
		while (insert != NULL && integ->n < insert->n)
		{
			swap_node(list, &insert, integ);
			print_list((const listint_t *)*list);
		}
	}
}
