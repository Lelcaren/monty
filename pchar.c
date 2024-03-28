#include "monty.h"

/**
 * pchar_stack - prints the character at the top of the stack
 * @head: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 * Description: This function prints the character at the top of the stack.
 * Return: No return value
 */
void pchar_stack(stack_t **head, unsigned int line_number)
{
	stack_t *current_node = *head;

	if (current_node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current_node->n < 0 || current_node->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current_node->n);
}

