#include "monty.h"

/**
 * multiply_stack - Multiplies the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number being executed.
 */
void multiply_stack(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

