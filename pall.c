#include "monty.h"

/**
 * pall_stack - prints all the elements in the stack
 * @head: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 * Description: This function prints all the elements in the stack.
 * Return: No return value
 */
void pall_stack(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head;

	(void)line_number;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

