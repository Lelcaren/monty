#include "monty.h"

/**
 * rotate_left - Rotates the stack to the top
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file (unused)
 *
 * Description: This function rotates the stack to the top by moving the
 * first element to the end of the stack.
 */
void rotate_left(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

