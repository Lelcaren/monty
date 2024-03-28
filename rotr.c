#include "monty.h"

/**
 * rotate_right - Rotates the stack to the bottom
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file (unused)
 *
 * Description: This function rotates the stack to the bottom by moving the
 * last element to the beginning of the stack.
 */
void rotate_right(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
